#include <iostream>

#include "Poly.h"

Poly::Poly()
{
	m_length = 1;
	m_list = new (nothrow) Node;
	m_list -> _power = 0;
	m_list -> _next = NULL;
}

//-----------------------------------------------------------------------------

Poly::Poly(int pow, Rational r)
{
	m_length = 1;
	m_list = new (nothrow) Node;
	m_list->_next = NULL;
	m_list->_power = pow;
	m_list->_rational = r;
}

//-----------------------------------------------------------------------------

Poly::Poly(Rational r)
{
	m_length = 1;
	m_list = new (nothrow) Node;
	m_list->_next = NULL;
	m_list->_power = 1;
	m_list->_rational = r;
}

//-----------------------------------------------------------------------------

int Poly::get_power()
{
	return m_list->_power;
}