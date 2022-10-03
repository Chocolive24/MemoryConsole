#pragma once
#include "Pattern.h"
#include "../../libs/ConsoleViewController/ConsoleViewController.h"

class Card
{
private:
	Pattern _pattern;
	Console::Background _background { Console::Background::DARK_GRAY };
	Console::Foreground _foreground{ Console::Foreground::LIGHT_MAGENTA };
	bool _selected{ false };
	bool _found{ false };

public:
	Card() = default;
	Card(Pattern pattern, Console::Foreground foreground = Console::Foreground::LIGHT_MAGENTA);

	Pattern GetPattern() { return _pattern; }
	Console::Background GetBackground() { return _background; }
	Console::Foreground GetForeground() { return _foreground; }
	bool IsSelected() { return _selected; }
	bool IsFound() { return _found; }
	void SetSelected(bool selected) { _selected = selected; }
	void SetFound() { _found = true; }
};
