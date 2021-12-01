#include "Cell.h"


//-------------------------------------------------
Cell::Cell(const string txt, const sf::Vector2f location, const sf::Color color)
	:m_text(txt), m_location(location), m_color(color)
{
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}
//-------------------------------------------------
void Cell::draw(sf::RenderWindow& window) const
{
	window.draw(createShape());
	window.draw(createText());
}
//--------------------------------------------------------
sf::Text Cell::createText() const
{
	auto result = sf::Text(m_text, m_font);
	result.setCharacterSize(16);
	result.setFillColor(sf::Color::Black);
	result.setPosition(m_location.x + LEN_CELL/2, m_location.y + LEN_CELL/2);
	const auto rect = result.getLocalBounds();
	result.setOrigin(rect.width / 2, rect.height / 2);
	return result;
}
//-------------------------------------------------
sf::RectangleShape Cell::createShape() const
{
	auto cell = sf::RectangleShape({ LEN_CELL, LEN_CELL });
	cell.setOutlineThickness(5);
	cell.setFillColor(m_color);
	cell.setOutlineColor(sf::Color::Black);
	cell.setPosition(m_location);
	return cell;
}
//------------------------------------------------------------------
bool Cell::handleClick(const sf::Vector2f& location)
{
	if (createShape().getGlobalBounds().contains(location))
		return true;
	return false;
}
//------------------------------------------------------------------
void Cell::setText(const string txt)
{
	m_text = txt;
}
//------------------------------------------------------------------
void Cell::setLocation(const sf::Vector2f& location)
{
	m_location = location;
}
//------------------------------------------------------------------
sf::Vector2f Cell::getLocation() const
{
	return m_location;
}
//------------------------------------------------------------------
string Cell::getText() const
{
	return m_text;
}