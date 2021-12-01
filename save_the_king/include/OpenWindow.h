#pragma once
#include <SFML/Graphics.hpp>
#include "MenuBar.h"
#include "BoardSfml.h"

class OpenWindow
{
public:
    OpenWindow();
    void run();
    void printFirstMessage(bool& first_time);
private:
    sf::RenderWindow m_window;
    MenuBar m_menu_bar;
    BoardSfml m_board;
};


