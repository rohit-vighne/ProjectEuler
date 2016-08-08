#include "Fraction.hpp"

#include <cstdint>
#include <iostream>

template <typename T>
inline T getNthTerm(T n)
{
	if (n % 3 == 0)
		return n / 3 * 2;
	else if (n == 1)
		return 2;
	else
		return 1;
}

template <typename T>
inline Fraction<T> getConvergent(T n, T max)
{
	if (n == max)
		return getNthTerm<T>(n);
	return getConvergent<T>(n + 1, max).addToRecip(getNthTerm<T>(n));
}

template <typename T>
inline Fraction<T> getConvergent(T max)
{
	return getConvergent<T>(1, max);
}

int main()
{
	auto res = getConvergent<std::intmax_t>(40);
	std::cout << res << std::endl;

	auto num = res.num;
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}

	std::cout << "Sum of digits: " << sum << std::endl;

	system("pause");
}