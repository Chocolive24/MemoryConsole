#include "GameView.h"
#include "../interactiveObjects/CardButton.h"

GameView::GameView(MainController mainController)
{
	std::vector<Console::InteractiveObject*> components;

	int x = 10;
	int y = 3;
	int i = 0;
	for (Card& card: mainController.GetCards())
	{
		components.emplace_back(new CardButton(ReturnPosition(x), ReturnPosition(y), card, [&card](CardButton* cardButton)
			{
				cardButton->GetCard().SetSelected(true);
			}
		));

		x += card.GetPattern().GetSprite().GetWidth() + 2;

		if (components.size() % 6 == 0)
		{
			x = 10;
			y += card.GetPattern().GetSprite().GetHeight() + 2;
		}
		i++;
	}

	setComponents(components);
}

void GameView::Update(Console::Controller* controller, Console::Screen& screen)
{
	View::Update(controller, screen);

	screen.Draw(Console::Text{ .Str = "FPS: " + std::to_string(controller->CurrentFPS), .X = 1, .Y = 1 });
}

void GameView::OnKeyPressed(Console::Controller* controller, char key)
{
	if (key == Console::Key::Right)
	{
		IncrementCurrentButton();
	}
	else if (key == Console::Key::Left)
	{
		DecrementCurrentButton();
	}
	else if (key == Console::Key::Down)
	{
		SetCurrentButton(GetCurrentButton() + 6);
	}
	else if (key == Console::Key::Up)
	{
		SetCurrentButton(GetCurrentButton() - 6);
	}

	View::OnKeyPressed(controller, key);
}
