#pragma once
#include "List.h"
#include "Rational.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::nothrow;

class Poly
{
public:
	Poly();
	Poly(Rational r);
	Poly(int pow, Rational r);
	int get_power();
private:
	int m_length;
	Node* m_list;
};
