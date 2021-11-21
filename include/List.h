#pragma once
#include "Rational.h"

struct Node
{
	Rational _rational;
	int _power;
	Node* _next;
};