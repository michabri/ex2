#include "MenuBar.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

//--------------------------------------------------------
MenuBar::MenuBar()
	:m_color(sf::Color::Cyan), m_size(1000.f, 50.f),
	m_objects{"K", "M", "W", "T", "=" , "#", "*", "!", "F", "X", "@", "DEL","SAV"},
	m_index(0)
{
	m_font_text.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}
//--------------------------------------------------------
void MenuBar::setMenuBar()
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		sf::Vector2f location(i * LEN_CELL, 0);
		Cell cell(m_objects[i], location, sf::Color::Cyan);
		m_cells.push_back(cell);
	}
}
//--------------------------------------------------------
void MenuBar::draw(sf::RenderWindow& window) const
{
	//draw menu bar
	auto menu_bar = sf::RectangleShape(m_size);
	menu_bar.setFillColor(m_color);
	menu_bar.setOutlineThickness(1);
	menu_bar.setOutlineColor(sf::Color::Black);
	window.draw(menu_bar);
	for (int i = 0; i < m_objects.size(); i++)
	{	
		m_cells[i].draw(window);
	}
}
//------------------------------------------------------------------
bool MenuBar::handleClick(const sf::Vector2f& location)
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		if (m_cells[i].handleClick(location))
		{
			if(i != m_objects.size()-1)
				m_index = i;
			return true;
		}
	}
	return false;
}
//------------------------------------------------------------------
string MenuBar::getText() const
{
	if(m_index < 11)
		return m_cells[m_index].getText();
	return " ";
}
