#include "GameView.h"

GameView::GameView(MainController mainController)
{
	//TODO: Add interactive components like buttons
	std::vector<Console::InteractiveObject*> components;

	int x = 3;
	int y = 3;
	for (Card& card: mainController.GetCards())
	{
		//components.emplace_back(new Console::ImageButton());
		x += card.GetPattern().GetSprite().GetWidth() + 2;

		if (components.size() % 6 == 0)
		{
			x = 3;
			y += card.GetPattern().GetSprite().GetHeight() + 2;
		}
	}
}

void GameView::Update(Console::Controller* controller, Console::Screen& screen)
{
	View::Update(controller, screen);
}

void GameView::OnKeyPressed(Console::Controller* controller, char key)
{

	View::OnKeyPressed(controller, key);
}
