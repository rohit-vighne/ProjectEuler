#include <iostream>

int main()
{
	int largest = 0;
	int largestP;

	for (int p = 1000; p >= 12; p -= 2)
	{
		int solutions = 0;
		for (int c = 5; c < p / 2; ++c)
		{
			int a;
			for (int b = c - 1; b > (a = p - c - b); --b)
			{
				if (a * a + b * b == c * c)
					++solutions;
			}
		}

		if (solutions > largest)
		{
			largest = solutions;
			largestP = p;
		}
	}

	std::cout << largestP << std::endl;
	system("pause");
}