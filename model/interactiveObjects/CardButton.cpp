#include "CardButton.h"

CardButton::CardButton(const std::function<int(Console::Screen)> getX, const std::function<int(Console::Screen)> getY,
                       int index, const std::function<void(MainController* mainController, const CardButton* cardButton)> onClick, Console::Background background, Console::Foreground foreground,
                       const bool xCentered)
	: InteractiveObject(getX, getY, xCentered)
{
	_index = index;
	_onClick = onClick;
	_background = background;
	_foreground = foreground;
}

void CardButton::Draw(Console::Controller* controller, Console::Screen& screen, const bool selected)
{
	const auto mainController = dynamic_cast<MainController*>(controller);
	auto background = Console::Background::DARK_GRAY;
	auto foreground = Console::Foreground::LIGHT_MAGENTA;
	int y = _getY(screen);
	int x = _getX(screen);
	Console::Image image = mainController->GetHiddenImage();
	Card& card = mainController->GetCards()[_index];

	if (card.IsFound() || card.IsSelected())
	{
		background = Console::Background::WHITE;
		foreground = _foreground;
		image = card.GetPattern().GetSprite();
	}

	if (selected)
	{
		background = Console::Background::ULTRA_WHITE;
	}

	for (const std::string& row : image.GetImage())
	{
		screen.Draw(Console::Text{
			.Str = row, .X = x, .Y = y, .XCentered = _xCentered, .Background = background, .Foreground = foreground
		});
		y++;
	}
}

void CardButton::OnKeyPress(Console::Controller* controller, const char key)
{
	if (key == Console::Key::Enter)
	{
		_onClick(dynamic_cast<MainController*>(controller), this);
	}
}
