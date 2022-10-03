#include "VictoryView.h"

#include "GameView.h"

VictoryView::VictoryView()
{
	setComponents({
		new Console::BasicButton("Play again", GetMiddleScreen(), ReturnPosition(12), [](Console::Controller* controller)
		{
			controller->ChangeView(new GameView(dynamic_cast<MainController*>(controller)));
		})
	});
}

void VictoryView::Update(Console::Controller* controller, Console::Screen& screen)
{
	View::Update(controller, screen);

	screen.Draw(Console::Text{ .Str = "You won the memory !", .X = screen.GetWidth() / 2, .Y = 5 , .XCentered = true });
}
