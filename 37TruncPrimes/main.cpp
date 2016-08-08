#include <iostream>
#include <cmath>

inline bool isNotPrime(const int n)
{
	if (n <= 1)
		return true;

	const int lim = std::sqrt(n);
	for (int x = 2; x <= lim; ++x)
		if (n % x == 0)
			return true;

	return false;
}

inline bool isTruncPrimeRight(int n)
{
	while (n)
	{
		if (isNotPrime(n))
			return false;

		n /= 10;
	}

	return true;
}

inline bool isTruncPrimeLeft(int n)
{
	int max10 = 1;
	{
		int t = n;
		while (t > 9)
		{
			t /= 10;
			max10 *= 10;
		}
	}

	while (n)
	{
		if (isNotPrime(n))
			return false;

		n -= (n / max10) * max10;
		max10 /= 10;
	}

	return true;
}

inline bool isTruncPrime(const int n)
{
	return isTruncPrimeRight(n) && isTruncPrimeLeft(n);
}

int main()
{
	int sum = 0;
	int nTruncPrimes = 0;
	for (int n = 11; nTruncPrimes < 11; n += 2)
	{
		if (isTruncPrime(n))
		{
			sum += n;
			++nTruncPrimes;
		}
	}

	std::cout << sum << std::endl;
	system("pause");
}
