#include "VictoryView.h"

#include "GameView.h"

VictoryView::VictoryView()
{
	setComponents({
		new Console::BasicButton("Play again", Position(0.5f), Position(12), [](Console::Controller* controller)
		{
			const auto mainController = dynamic_cast<MainController*>(controller);
			mainController->IntializeGame();
			controller->ChangeView(new GameView(mainController));
		}, true)
	});
}

void VictoryView::Update(Console::Controller* controller, Console::Screen& screen)
{
	View::Update(controller, screen);

	screen.Draw(Console::Text{ .Str = "You won the memory !", .X = screen.GetWidth() / 2, .Y = 5 , .XCentered = true });
}
