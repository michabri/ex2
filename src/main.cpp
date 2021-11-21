#include <iostream>
#include "Rational.h"
#include "Poly.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    /*Rational r1(1, 4);
    Rational r2(16, 8);
    Rational r3(1, 1);

    r3 = r1 + r2;
    r3 += r2;

    if (r3 >= r2)
    {
        cout << "1" << endl;
    }

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    */

    Rational r1(2, 5);
    Poly p;
    Rational r;
    cin >> r;
    cout << r << endl;
    r1--;
    cout << r1 << endl;

    exit(EXIT_SUCCESS);
}
