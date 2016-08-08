#include <cmath>

bool isPrime(int n)
{
	if (n <= 1)
		return false;

	int lim = std::sqrt(n);
	for (int x = 2; x <= lim; ++x)
		if (n % x == 0)
			return false;

	return true;
}
