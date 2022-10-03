#include "CardButton.h"

CardButton::CardButton(std::function<int(Console::Screen)> getX, std::function<int(Console::Screen)> getY,
                       Card& card, const std::function<void(CardButton* cardButton)>& onClick, const bool xCentered,
	const bool yCentered) : Console::ImageButton(getX, getY, card.GetPattern().GetSprite(), []() {},
                                                                    xCentered, yCentered,
                                                                    card.GetBackground(), card.GetForeground())
{
	_card = card;
	_onClick = onClick;
}

void CardButton::Draw(Console::Screen& screen, const bool selected)
{
	auto background = Console::Background::WHITE;
	auto foreground = Console::Foreground::BLACK;
	int y = _getY(screen);
	int x = _getX(screen);
	Console::Image image = PatternHidden().GetSprite();

	if (_yCentered)
	{
		y -= _image.GetHeight() / 2;
	}

	if (_card.IsFound() || _card.IsSelected())
	{
		background = _background;
		foreground = _foreground;
		image = _card.GetPattern().GetSprite();
	}

	if (selected)
	{
		background = Console::Background::YELLOW;
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
		_onClick(this);
	}
}
