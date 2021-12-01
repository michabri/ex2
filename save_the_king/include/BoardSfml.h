#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

const int CHARACTER = 4;

using std::vector;

class BoardSfml
{
public:
    BoardSfml(const int row = 10, const int col = 10);
    void setBoard();
    void draw(sf::RenderWindow& window) const;
    void setRow(const int row);
    void setCol(const int col);
    bool handleClick(const sf::Vector2f& location);
    void setTextInCell(const string text);

private:
    vector<Cell> m_board;
    int m_index;
    int m_row;
    int m_col;
};