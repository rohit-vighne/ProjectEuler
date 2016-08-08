#include <cmath>
#include <iostream>

bool isPrime(int n)
{
	if (n % 2 == 0)
		return false;

	const int lim = std::sqrt(n);
	for (int d = 3; d <= lim; d += 2)
		if (n % d == 0)
			return false;
	
	return true;
}

bool followsConjecture(int n)
{
	for (int part, root = 1; part = 2 * root * root, part <= n - 3; ++root)
		if (isPrime(n - part))
			return true;

	return false;
}

int main()
{
	int n = 9;
	for (;; n += 2)
		if (!isPrime(n))
			if (!followsConjecture(n))
				break;

	std::cout << n << std::endl;
	system("pause");
}