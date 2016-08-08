#include <iostream>
#include <cmath>
//#include <utility>

#include <vector>
#include <algorithm>

class Permutation
{
	std::vector<int> seq;

public:
	Permutation(int n)
	{
		do {
			seq.push_back(n % 10);
		} while (n /= 10);
	}

	// Checks if both sequences contain the same elements
	bool operator==(const Permutation& other)
	{
		return std::is_permutation(seq.begin(), seq.end(), other.seq.begin(), other.seq.end());
	}

	std::ostream& operator<<(std::ostream& os)
	{
		for (int i = 0, size = seq.size(); i < size; ++i)
			std::cout << seq[i];
	}
};

/*
void numToSeq(int n, int* seq, int len)
{
	while (len--)
	{
		seq[len] = n % 10;
		n /= 10;
	}
}

int seqToNum(int* seq, int size)
{
	int n = 0;
	for (int i = 0; i < size; ++i)
		n += seq[size - i - 1] * pow(10, i);

	return n;
}

void printSeq(int* seq, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << seq[i] << ',';
	std::cout << std::endl;
}

// Changes seq in-place to be the next lexicographical permutation
// Returns true if there may be more (higher) permutations, and false otherwise
bool nextPermutation(int* seq, int size)
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

// Assumes no repeats
bool isPermutation(int *seqA, int* seqB, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int j;
		for (j = 0; j < size; ++j)
			if (seqA[i] == seqB[j])
				break;

		if (j == size)
			return false;
	}

	return true;
}
*/

// The input must be greater than 2
inline bool isPrime(int n)
{
	if (n % 2 == 0)
		return false;

	int lim = std::sqrt(n);
	for (int x = 3; x <= lim; x += 2)
		if (n % x == 0)
			return false;

	return true;
}

/*
int main()
{
	for (int a = 1001; a <= 9999; a += 2)
	{
		if (isPrime(a) && a != 1487)
		{
			int seqA[4];
			numToSeq(a, seqA, 4);

			while (nextPermutation(seqA, 4))
			{
				int b = seqToNum(seqA, 4);
				if (isPrime(b))
				{
					int c = b + (b - a);

					if (c > 9999)
						continue;

					int seqC[4];
					numToSeq(c, seqC, 4);

					if (isPrime(c) && isPermutation(seqC, seqA, 4))
					{
						std::cout << a << b << c << std::endl;
						system("pause");
						return 0;
					}
				}
			}
		}
	}
}
*/

int main()
{
	for (int a = 1001; a <= 9999; a += 2)
	{
		if (isPrime(a) && a != 1487)
		{
			Permutation seqA(a);

			int b = a + 3330;
			if (isPrime(b))
			{
				Permutation seqB(b);

				if (seqB == seqA)
				{
					int c = b + 3330;
					if (isPrime(c))
					{
						Permutation seqC(c);

						if (seqC == seqA)
						{
							std::cout << a << b << c << std::endl;
							system("pause");
							return 0;
						}
					}
				}
			}
		}
	}
}