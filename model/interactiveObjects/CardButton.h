#pragma once
#include "../../libs/ConsoleViewController/view/interactive/objects/ImageButton.h"
#include "../card/Card.h"
#include "../controller/MainController.h"

class CardButton : public Console::InteractiveObject
{
private:
	int _index;
	std::function<void(MainController* mainController, const CardButton* cardButton)> _onClick;
	Console::Background _background;
	Console::Foreground _foreground;

	inline static Console::Image _hiddenImage = PatternHidden().GetSprite();
public:
	CardButton(std::function<int(Console::Screen)> getX, std::function<int(Console::Screen)> getY, int index,
				const std::function<void(MainController* mainController, const CardButton* cardButton)> onClick, Console::Background background, Console::Foreground foreground,
				const bool xCentered = false);

	void Draw(Console::Controller* controller, Console::Screen& screen, bool selected) override;
	int GetIndex() const { return _index; }
	void OnKeyPress(Console::Controller* controller, const char key) override;
};

