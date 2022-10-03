#pragma once
#include "../../libs/ConsoleViewController/ConsoleViewController.h"
#include "../card/Card.h"

int constexpr CARD_PER_ROW = 6;

class MainController : public Console::Controller
{
private:
	std::vector<Card> _cards;
	Console::Image _hiddenImage;
public:
	MainController();

	std::vector<Card>& GetCards() { return _cards; }
	Console::Image GetHiddenImage() { return _hiddenImage; }

	void IntializeGame();
	bool IsACardSelected();
	Card& GetSelectedCard();
};

