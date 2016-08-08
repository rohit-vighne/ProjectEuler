#pragma once

#include <utility>
#include <ostream>

template <typename T>
struct Fraction
{
	T num, den = 1;

	Fraction(T val) :
		num(val)
	{

	}

	Fraction& addToRecip(T a)
	{
		std::swap(num, den);
		num += a * den;

		std::cout << *this << std::endl;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction& frac)
	{
		os << frac.num << '/' << frac.den;
		return os;
	}
};
