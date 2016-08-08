#include <cstdlib>
#include <utility>
#include <iostream>

// Changes seq in-place to be the next lexicographical permutation
// Returns true if there may be more (higher) permutations, and false otherwise
template <typename T>
bool nextPermutation(T* seq, int size)
{
	// Find pivot point
	int i;
	for (i = size - 2; i >= 0; --i)
		if (seq[i] < seq[i + 1])
			break;

	// Already the highest permutation
	if (i < 0)
		return false;

	// Find next-highest element
	int j;
	for (j = size - 1; j > i; --j)
		if (seq[j] > seq[i])
			break;

	// Swap that with pivot
	std::swap(seq[i], seq[j]);

	// Reverse the suffix (after the pivot)
	i += 1;
	for (j = size - 1; j > i; --j, ++i)
		std::swap(seq[j], seq[i]);

	// There may be more permutations
	return true;
}

int main()
{
	const int primes[] = { 2, 3, 5, 7, 11, 13, 17 };

	int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	long long sum = 0;

	while (nextPermutation(digits, 10))
	{
		std::size_t i = 1, last = 8;
		for (; i < last; ++i)
		{
			int substr = digits[i] * 100 + digits[i + 1] * 10 + digits[i + 2];
			if (substr % primes[i - 1])
				break;
		}

		if (i == last)
		{
			sum +=
				digits[0] * 1000000000LL +
				digits[1] * 100000000LL +
				digits[2] * 10000000LL +
				digits[3] * 1000000LL +
				digits[4] * 100000LL +
				digits[5] * 10000LL +
				digits[6] * 1000LL +
				digits[7] * 100LL +
				digits[8] * 10LL +
				digits[9] * 1LL;
		}
	}

	std::cout << sum << std::endl;
	system("pause");
}