#ifdef notdef
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// n must be odd and greater than 1
bool isPrime(int n)
{
	const int lim = std::sqrt(n);
	for (int x = 3; x <= lim; x += 2)
		if (n % x == 0)
			return false;

	return true;
}

std::vector<int> getDigits(int n)
{
	std::vector<int> digits;
	while (n)
	{
		digits.push_back(n % 10);
		n /= 10;
	}

	return digits;
}

int digitsToNum(const std::vector<int>& digits)
{
	int num = 0;
	for (auto it = digits.rbegin(); it != digits.rend(); ++it)
	{
		num *= 10;
		num += *it;
	}

	return num;
}

int main()
{
	std::set<std::vector<int>> primes;
	int count = 1;

	for (int i = 3; i < 1000000; i += 2)
	{
		if (isPrime(i))
		{
			auto origDigits = getDigits(i);
			auto digits = origDigits;

			do {
				primes.insert(digits);
				std::next_permutation(digits.begin(), digits.end());
				if (!isPrime(digitsToNum(digits)))
					break;
			} while (primes.find(digits) == primes.end());

			if (digits == origDigits)
			{
				std::cout << digitsToNum(digits) << std::endl;
				++count;
			}
		}
	}

	std::cout << count << std::endl;
	system("pause");
}
#endif