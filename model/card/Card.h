#pragma once
#include "Pattern.h"
#include "../../lib/ConsoleViewController.h"

class Card
{
private:
	Pattern _pattern { PatternHidden() };
	Console::Background _background { Console::Background::WHITE };
	Console::Foreground _foreground{ Console::Foreground::BLACK };
	bool _selected{ false };
	bool _found{ false };

public:
	Card(Pattern pattern, Console::Foreground foreground = Console::Foreground::BLACK);

	Pattern GetPattern() { return _pattern; }
};
