#pragma once
#include "../../lib/ConsoleViewController.h"
#include "../controller/MainController.h"

class GameView : public Console::View
{
public:
	GameView(MainController mainController);

	void Update(Console::Controller* controller, Console::Screen& screen) override;
	void OnKeyPressed(Console::Controller* controller, char key) override;
};

