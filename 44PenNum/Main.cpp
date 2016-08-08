#include <iostream>
#include <cmath>

static int constexpr getPentagonal(int n)
{
	return n * (n * 3 - 1) / 2;
}

static bool isPentagonal(int x)
{
	int test = 24 * x + 1;
	int root = std::sqrt(test);
	return (root * root == test) && (root % 6 == 5);
}

int main()
{
	for (int n = 1; ; ++n)
	{
		int x = getPentagonal(n);
		
		for (int m = n - 1; m > 0; --m)
		{
			int y = getPentagonal(m);
			int sum = x + y, diff = x - y;

			if (isPentagonal(sum) && isPentagonal(diff))
			{
				std::cout << diff << std::endl;
			}
		}
	}
}
