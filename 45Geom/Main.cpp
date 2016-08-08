#include <iostream>
#include <cmath>

bool isPentagonal(long long x)
{
	long long test = 24 * x + 1;
	long long root = std::sqrt(test);
	return (root * root == test) && (root % 6 == 5);
}

int main()
{
	for (long long n = 144; ; ++n)
	{
		long long hex = n * (2 * n - 1);
		if (isPentagonal(hex))
		{
			std::cout << hex << std::endl;
			system("pause");
			return 0;
		}
	}
}