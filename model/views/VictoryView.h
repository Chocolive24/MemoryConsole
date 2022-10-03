#pragma once
#include "../../libs/ConsoleViewController/ConsoleViewController.h"

class VictoryView : public Console::View
{
public:
	VictoryView();

	void Update(Console::Controller* controller, Console::Screen& screen) override;
};
