#include <cstdlib>
#include <iostream>

#include <Windows.h>

/*
double factorial(int n)
{
	if (n == 0)
		return 1;

	double res = n;
	while (--n > 1)
		res *= n;

	return res;
}
*/

/*
class FactorialCache
{
	std::vector<double> cache { 1.0, 1.0 };

public:
	double find(int n) const
	{
		if (n < cache.size())
			return cache[n];
		else
			return 0.0;
	}

	double insert(int n, double val)
	{
		if (n >= cache.size())
			cache.resize(n + 1, 0.0);

		return cache[n] = val;
	}
};

double factorial(int n)
{
	if (n <= 1)
		return 1;

	static FactorialCache cache;

	double found = cache.find(n);
	if (found)
		return found;
	else
		return cache.insert(n, n * factorial(n - 1));
}
*/

/*double factorial(int n)
{
	if (n <= 1)
		return 1;

	static double cache[99];

	double found = cache[n - 2];
	if (found)
		return found;
	else
		return cache[n - 2] = n * factorial(n - 1);
}*/

/*
double factorial(int n)
{
	static double cache[101] = { 1.0, 1.0 };
	static std::size_t i = 2;

	for (; i <= n; ++i)
		cache[i] = i * cache[i - 1];

	return cache[n];
}

double combinations(int n, int r)
{
	return factorial(n) / factorial(r) / factorial(n - r);
}
*/

int main()
{
	LARGE_INTEGER freq, startTime, endTime;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&startTime);

	double factorial[101] = { 1.0, 1.0 };

	for (std::size_t i = 2; i <= 100; ++i)
		factorial[i] = i * factorial[i - 1];

	const double minVal = 1000000.0;
	int count = 0;

	for (std::size_t n = 23; n <= 100; ++n)
		for (std::size_t r = 2; r <= n; ++r)
			if (factorial[n] / factorial[r] / factorial[n - r] > minVal)
				++count;

	QueryPerformanceCounter(&endTime);
	std::cout << (endTime.QuadPart - startTime.QuadPart) * 1000 / (double) (freq.QuadPart) << "ms" << std::endl;

	std::cout << count << std::endl;
	system("pause");
}