#pragma once
#include "../../libs/ConsoleViewController/view/interactive/objects/ImageButton.h"
#include "../card/Card.h"

class CardButton : public Console::ImageButton
{
private:
	Card _card;
	std::function<void(CardButton* cardButton)> _onClick;
public:
	CardButton(std::function<int(Console::Screen)> getX, std::function<int(Console::Screen)> getY, Card& card, 
				const std::function<void(CardButton* cardButton)>& onClick, const bool xCentered = false, const bool yCentered = false);

	void Draw(Console::Screen& screen, bool selected) override;
	Card& GetCard() { return _card; }
	void OnKeyPress(Console::Controller* controller, const char key) override;
};

