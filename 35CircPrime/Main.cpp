#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// n must be greater than 2
bool isPrime(int n)
{
	if (n % 2 == 0)
		return false;

	const int lim = std::sqrt(n);
	for (int x = 3; x <= lim; x += 2)
		if (n % x == 0)
			return false;

	return true;
}

int rotate(int n)
{
	int front = n % 10;
	n /= 10;

	int num = n;
	while (num)
	{
		num /= 10;
		front *= 10;
	}

	return front + n;
}

// Finds the number of circular primes that are less than the limit
// The limit must be greater than 2
int circPrimes(int limit)
{
	// 2 is already counted
	int count = 1;

	// For all odd numbers underneath the limit
	for (int n = 3; n < limit; n += 2)
	{
		if (isPrime(n))
		{
			int num = rotate(n);
			for (; num != n; num = rotate(num))
				if (!isPrime(num))
					break;

			if (num == n)
				++count;
		}
	}

	return count;
}

int main()
{
	std::cout << circPrimes(1000000) << std::endl;
	system("pause");
}