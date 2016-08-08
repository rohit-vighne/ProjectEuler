#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// n must be an odd number greater than 1
bool isPrime(int n)
{
	const int lim = std::sqrt(n);
	for (int x = 3; x <= lim; x += 2)
		if (n % x == 0)
			return false;

	return true;
}

template <typename T>
int toNum(const std::vector<T>& digits)
{
	int n = 0;
	for (auto it = digits.begin(); it != digits.end(); ++it)
	{
		n *= 10;
		n += *it;
	}

	return n;
}

int main()
{
	std::vector<int> digits { 7, 6, 5, 4, 3, 2, 1 };
	auto start = digits.begin(), end = digits.end();

	while (!digits.empty())
	{
		do
		{
			int last = digits.back();
			if (last % 2 == 0 || last == 5)
				continue;

			int n = toNum(digits);
			if (isPrime(n))
			{
				std::cout << n << std::endl;
				system("pause");
				return 0;
			}
		} while (std::prev_permutation(start, end));

		++start;
	}
}
