#pragma once

#include <cmath>
#include <vector>

struct Triangle {
	int a, b, c;
};

inline int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

auto getRightTriangles(int perim)
{
	std::vector<Triangle> triangles;

	int s = perim / 2;
	int mlim = std::sqrt(s);
	for (int m = 2; m <= mlim; ++m)
	{
		if (s % m == 0)
		{
			int pm = s / m;
			while (pm % 2 == 0)
				pm /= 2;

			int klim = 2 * m;

			for (int k = m + (m % 2) + 1; k < klim && k <= pm; k += 2)
			{
				if (pm % k == 0 && gcd(k, m) == 1)
				{
					int d = s / (k * m);
					int n = k - m;
					int mm = m * m, nn = n * n;

					triangles.emplace_back(Triangle {
						(mm - nn) * d, // a
						2 * m * n * d, // b
						(mm + nn) * d  // c
					});
					break;
				}
			}
		}
	}

	return triangles;
}
