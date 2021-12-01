#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

using std::vector;

class MenuBar
{
public:
    MenuBar();
    void setMenuBar();
    void draw(sf::RenderWindow& window) const;
    bool handleClick(const sf::Vector2f& location);
    string getText() const;
    
private:
    vector<Cell> m_cells;
    sf::Font m_font_text;
    sf::Vector2f m_size;
    sf::Color m_color;
    vector <string> m_objects;
    int m_index;
    
};