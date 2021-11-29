#pragma once

using std::ostream;
using std::istream;

class Rational
{
public:
	Rational();
	Rational(int numerator, int denumenator);
	void set_numerator(int numerator);
	void set_denumerator(int denumerator);
	int get_numerator() const;
	int get_denumerator() const;
	
private:
	int m_numerator;
	int m_denumerator;
};

Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
ostream& operator<<(ostream& os, const Rational& r);
istream& operator>>(istream& is, Rational& r);
Rational operator+=(Rational& r1, const Rational& r2);
Rational operator-=(Rational& r1, const Rational& r2);
Rational operator/=(Rational& r1, const Rational& r2);
Rational operator*=(Rational& r1, const Rational& r2);
Rational operator-(const Rational& r);
Rational operator+(const Rational& r);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator<(const Rational& r1, const Rational& r2);
void operator++(Rational& r, int);
void operator--(Rational& r, int);

int find_biggest_divider(int num, int denum);
void divide(int& num, int& denum, const int div);