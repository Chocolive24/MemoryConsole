#include <windows.h>

#include "libs/ConsoleViewController/ConsoleViewController.h"
#include "model/controller/MainController.h"

int main()
{
    // Set console to UTF-8 in order to display emojis
    SetConsoleOutputCP(CP_UTF8);

    Console::Screen::SetWindowSize(1000, 700);
    Console::Screen::CenterWindow();

    MainController mainController;
    mainController.Start();
}
