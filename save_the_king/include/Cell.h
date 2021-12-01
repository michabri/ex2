#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using std::string;
const int LEN_CELL = 50;
class Cell
{
public:
    Cell(const string txt, const sf::Vector2f location, const sf::Color color);
    void setText(const string txt);
    void draw(sf::RenderWindow& window) const;
    bool handleClick(const sf::Vector2f& location);
    void setLocation(const sf::Vector2f& location);
    sf::Vector2f getLocation() const;
    string getText() const;

private:
    sf::Text createText() const;
    sf::RectangleShape createShape() const;
    
    sf::Font m_font;
    string m_text;
    sf::Color m_color;
    sf::Vector2f m_location;
};
