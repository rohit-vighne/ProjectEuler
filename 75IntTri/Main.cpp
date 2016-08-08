#include <cmath>
#include <iostream>

/*
int nTriangles(int p)
{
	int count = 0;

	for (long long c = p / 2 - 1, min = p / 3; c > min; --c)
	{
		for (long long b = c - 1, a = p - c - b; b > a; --b, ++a)
		{
			printf("(%d, %d, %d)\n", a, b, c);

			if (a * a + b * b == c * c)
			{
				++count;
				break;
			}
		}
	}

	return count;
}
*/

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

bool singularTriangle(int p)
{
	bool found = false;

	p /= 2;
	int mlim = std::sqrt(p);
	for (int m = 2; m <= mlim; ++m)
	{
		if (p % m == 0)
		{
			int pm = p / m;
			while (pm % 2 == 0)
				pm /= 2;

			int klim = 2 * m;

			for (int k = m + (m % 2) + 1; k < klim && k <= pm; k += 2)
			{
				if (pm % k == 0 && gcd(k, m) == 1)
				{
					if (found)
						return false;
					else
						found = true;
					break;
				}
			}
		}
	}

	return found;
}

int main()
{
	/*
	int x = gcd(1, 2);
	std::cout << x;

	{
		auto triangles = getRightTriangles(1'500'000);
		for (const auto& triangle : triangles)
			std::cout << '(' << triangle.a << ',' << triangle.b << ',' << triangle.c << ')' << std::endl;
	}
	system("pause");
	*/

	int count = 0;
	for (int n = 12; n <= 1'500'000; n += 2)
		if (singularTriangle(n))
			++count;

	std::cout << count << std::endl;
	system("pause");
}