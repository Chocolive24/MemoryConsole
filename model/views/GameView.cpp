#include "GameView.h"
#include "../../libs/ConsoleViewController/utilities/Utility.h"

void OnCardClick(MainController* mainController, const CardButton* cardButton)
{
	Card& currentCard = mainController->GetCards()[cardButton->GetIndex()];

	if (!currentCard.IsFound())
	{
		if (mainController->IsACardSelected())
		{
			Card& secondCard = mainController->GetSelectedCard();
			currentCard.SetSelected(true);
			Utility::sleep(1000);

			if (secondCard.GetPattern().GetType() == currentCard.GetPattern().GetType())
			{
				secondCard.SetFound();
				currentCard.SetFound();
			}

			secondCard.SetSelected(false);
			currentCard.SetSelected(false);
		}
		else
		{
			currentCard.SetSelected(true);
		}
	}
}

GameView::GameView(MainController* mainController)
{
	std::vector<Console::InteractiveObject*> components;

	int x = 10;
	int y = 3;
	int i = 0;
	for (Card& card: mainController->GetCards())
	{
		components.emplace_back(new CardButton(ReturnPosition(x), ReturnPosition(y), i, OnCardClick, card.GetBackground(), 
			card.GetForeground()));

		x += card.GetPattern().GetSprite().GetWidth() + 2;

		if (components.size() % CARD_PER_ROW == 0)
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
	screen.Draw(Console::Text{ .Str = "Pixels: " + std::to_string(screen.PixelChanged), .X = 1, .Y = 2 });
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
