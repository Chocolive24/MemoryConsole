#include "MainController.h"

#include <algorithm>
#include <random>

#include "../views/GameView.h"

MainController::MainController()
{
	IntializeGame();
	ChangeView(new GameView(*this));
}

void MainController::IntializeGame()
{
	_cards = {};
	std::vector<Pattern> patterns = {
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
		for (auto pattern: patterns)
		{
			_cards.emplace_back(Card(pattern));
		}
	}

	std::shuffle(this->_cards.begin(), this->_cards.end(), std::random_device());
}
