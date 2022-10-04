#pragma once
#include "../../libs/ConsoleViewController/view/interactive/objects/ImageButton.h"
#include "../card/Card.h"
#include "../controller/MainController.h"

class CardButton : public Console::InteractiveObject
{
private:
	int _index;
	std::function<void(MainController* mainController, CardButton* cardButton)> _onClick;
	Console::Background _background;
	Console::Foreground _foreground;
	Card _card;

	//inline static Console::Image _hiddenImage = PatternHidden().GetSprite();
public:
	CardButton(Position x, Position y, int index,
				const std::function<void(MainController* mainController, CardButton* cardButton)> onClick, Console::Background background, Console::Foreground foreground, const bool xCentered = false);

	void Draw(Console::Controller* controller, Console::Screen& screen, bool selected) override;
	int GetIndex() const { return _index; }
	void OnKeyPress(Console::Controller* controller, const char key) override;
};

