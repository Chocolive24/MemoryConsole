#pragma once
#include "../../libs/ConsoleViewController/ConsoleViewController.h"
#include "../card/Card.h"

class MainController : public Console::Controller
{
private:
	std::vector<Card> _cards;

public:
	MainController();

	std::vector<Card> GetCards() { return _cards; }

	void IntializeGame();
};

