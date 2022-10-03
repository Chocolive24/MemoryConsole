#include "MainController.h"

#include <algorithm>
#include <random>

#include "../views/GameView.h"

MainController::MainController()
{
	_hiddenImage = PatternHidden().GetSprite();
	IntializeGame();
	ChangeView(new GameView(this));
}

void MainController::IntializeGame()
{
	_cards = {};
	const std::vector<Pattern> patterns = {
		PatternCat(),
		PatternClubs(),
		PatternDiamond(),
		PatternFace(),
		PatternHeart(),
		PatternPlus(),
		PatternPray(),
		PatternSpade(),
		PatternX()
	};

	for (int i = 0; i < 2; i++)
	{
		for (const auto& pattern: patterns)
		{
			Card card = Card(pattern);
			_cards.emplace_back(card);
		}
	}

	std::shuffle(this->_cards.begin(), this->_cards.end(), std::random_device());
}

bool MainController::IsACardSelected()
{
	for (Card& card: _cards)
	{
		if (card.IsSelected())
		{
			return true;
		}
	}

	return false;
}

Card& MainController::GetSelectedCard()
{
	for (Card& card : _cards)
	{
		if (card.IsSelected())
		{
			return card;
		}
	}
}

bool MainController::IsAllCardsFound()
{
	for (Card& card : _cards)
	{
		if (!card.IsFound())
		{
			return false;
		}
	}

	return true;
}
