#include <windows.h>

#include "libs/ConsoleViewController/ConsoleViewController.h"
#include "model/controller/MainController.h"

int main()
{
    Console::Screen::SetWindowSize(750, 700);
    Console::Screen::CenterWindow();

    MainController mainController;
    mainController.Start();
}
