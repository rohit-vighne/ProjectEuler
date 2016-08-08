#include <iostream>

int next(int n)
{
	int sum = 0;
	while (n)
	{
		int d = n % 10;
		sum += d * d;
		n /= 10;
	}

	return sum;
}

int main()
{
	int count = 0;
	for (int n = 2; n < 10000000; ++n)
	{
		int m = n;
		while (m != 89 && m != 1)
			m = next(m);

		if (m == 89)
			++count;
	}

	std::cout << count << std::endl;
	system("pause");
}