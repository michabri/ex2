#include <iostream>
#include "Rational.h"



Rational::Rational()
	:m_numerator(0), m_denumerator(1)
{}

//-----------------------------------------------------------------------------

Rational::Rational(int numerator, int denumerator)
{
	if ((denumerator < 0 && numerator > 0) || 
		(denumerator < 0 && numerator < 0))
	{
		denumerator = denumerator * (-1);
		numerator = numerator * (-1);
	}
	int div = find_biggest_divider(numerator, denumerator);
	divide(numerator, denumerator, div);
	m_numerator = numerator;
	m_denumerator = denumerator;
}

//-----------------------------------------------------------------------------

void Rational::set_numerator(int numerator)
{
	m_numerator = numerator;
}

//-----------------------------------------------------------------------------

void Rational::set_denumerator(int denumerator)
{
	m_denumerator = denumerator;
}

//-----------------------------------------------------------------------------

Rational operator+(const Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_denumerator() + 
			  r2.get_numerator() * r1.get_denumerator();
	int denum = r1.get_denumerator() * r2.get_denumerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);

	return Rational(num, denum);

}

//-----------------------------------------------------------------------------

Rational operator-(const Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_denumerator() -
		r2.get_numerator() * r1.get_denumerator();
	int denum = r1.get_denumerator() * r2.get_denumerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);

	return Rational(num, denum);
}

//-----------------------------------------------------------------------------

Rational operator*(const Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_numerator();
	int denum = r1.get_denumerator() * r2.get_denumerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);

	return Rational(num, denum);
}

//-----------------------------------------------------------------------------

Rational operator/(const Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_denumerator();
	int denum = r1.get_denumerator() * r2.get_numerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);

	return Rational(num, denum);
}

//-----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Rational& r)
{
	os << r.get_numerator() << "/" << r.get_denumerator();
	return os;
}

//-----------------------------------------------------------------------------

istream& operator>>(istream& is, Rational& r)
{
	int num, denum;
	is >> num;
	is.ignore(1);
	is >> denum;
	r.set_numerator(num);
	r.set_denumerator(denum);
	return is;
}

//-----------------------------------------------------------------------------

Rational operator+=(Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_denumerator() + 
			  r2.get_numerator() * r1.get_denumerator();
	int denum = r1.get_denumerator() * r2.get_denumerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);
	r1.set_numerator(num);
	r1.set_denumerator(denum);
	return r1;
}

//-----------------------------------------------------------------------------

Rational operator-=(Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_denumerator() -
		r2.get_numerator() * r1.get_denumerator();
	int denum = r1.get_denumerator() * r2.get_denumerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);
	r1.set_numerator(num);
	r1.set_denumerator(denum);
	return r1;
}

//-----------------------------------------------------------------------------

Rational operator/=(Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_denumerator();
	int denum = r1.get_denumerator() * r2.get_numerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);
	r1.set_numerator(num);
	r1.set_denumerator(denum);
	return r1;
}

//-----------------------------------------------------------------------------

Rational operator*=(Rational& r1, const Rational& r2)
{
	int num = r1.get_numerator() * r2.get_numerator();
	int denum = r1.get_denumerator() * r2.get_denumerator();
	int div = find_biggest_divider(num, denum);
	divide(num, denum, div);
	r1.set_numerator(num);
	r1.set_denumerator(denum);
	return r1;
}

//-----------------------------------------------------------------------------

Rational operator-(const Rational& r)
{
	return Rational(-r.get_numerator(), r.get_denumerator());
}

//-----------------------------------------------------------------------------

Rational operator+(const Rational& r)
{
	return Rational(abs(r.get_numerator()), r.get_denumerator());
}

//-----------------------------------------------------------------------------

void operator++(Rational& r, int)
{
	Rational r1(1, 1);
	r += r1;
}

//-----------------------------------------------------------------------------

void operator--(Rational& r, int)
{
	Rational r1(1, 1);
	r -= r1;
}

//-----------------------------------------------------------------------------

bool operator==(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() ==
		   r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator!=(const Rational& r1, const Rational& r2)
{
	return(!(r1 == r2));
}

//-----------------------------------------------------------------------------

bool operator<=(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() <=
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator>=(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() >=
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator>(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() >
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator<(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() <
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------
int Rational::get_numerator() const
{
	return m_numerator;
}

//-----------------------------------------------------------------------------

int Rational::get_denumerator() const
{
	return m_denumerator;
}

//-----------------------------------------------------------------------------

int find_biggest_divider(int num, int denum)
{
	int div = abs(num);
	while (div > 1)
	{
		if (num % div == 0 && denum % div == 0)
			return div;
		div--;
	}
	return 1;
}

//-----------------------------------------------------------------------------

void divide(int& num, int& denum, const int div)
{
	num /= div;
	denum /= div;
}