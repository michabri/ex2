#include <iostream>
#include <string>

#include "OpenWindow.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

OpenWindow::OpenWindow()
    : m_window(sf::VideoMode(1000, 1000), "Board game")
{}
//--------------------------------------------------------------------
void OpenWindow::run()
{
    bool first_time = true;
    bool pressed_text_in_menu_bar = false;
    string txt_menu_bar;
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::White);
        if (first_time)
            printFirstMessage(first_time);
        else
        {
            m_menu_bar.draw(m_window);
            m_board.draw(m_window);
            m_window.display();
        }

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            
            case sf::Event::MouseButtonReleased:
                auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }); 
                if (m_menu_bar.handleClick(location))
                {
                    txt_menu_bar = m_menu_bar.getText();
                    break;
                }
                else if (m_board.handleClick(location))
                {
                    m_board.setTextInCell(txt_menu_bar);
                }
                break;
            }
        }
    }
}
//--------------------------------------------------------
void OpenWindow::printFirstMessage(bool &first_time)
{
    sf::Text input;
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    input.setFont(font);
    input.setString("Enter the size of your board");
    input.setCharacterSize(50);
    input.setFillColor(sf::Color::Black);
    input.setPosition(100, 100);
    m_window.draw(input);
    m_window.display();

    cout << "Enter the size of the rows and the size of the cols\n";
    int row, col;
    cin >> row >> col;
    m_board.setRow(row);
    m_board.setCol(col);
    m_board.setBoard();
    m_menu_bar.setMenuBar();
    first_time = false;
}