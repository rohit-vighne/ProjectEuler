#include <iostream>

int getDigit(int i, int offset)
{
	while (offset-- > 0)
		i /= 10;

	return i % 10;
}

int main()
{
	const int maxN = 1000000;
	int targetN = 1;
	int lenSum = 0;

	int curLen = 1;
	int nextLenStep = 10;

	int prod = 1;

	for (int i = 1; ; ++i)
	{
		if (i == nextLenStep)
		{
			++curLen;
			nextLenStep *= 10;
		}

		lenSum += curLen;
		if (lenSum >= targetN)
		{
			prod *= getDigit(i, lenSum - targetN);

			targetN *= 10;
			if (targetN > maxN)
				break;
		}
	}

	std::cout << prod << std::endl;
}