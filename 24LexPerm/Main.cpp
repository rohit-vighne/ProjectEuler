#include <iostream>
#include <utility>

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
	int seq[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	constexpr int seqLen = sizeof(seq) / sizeof(seq[0]);

	for (int i = 1; i < 1000000; ++i)
		nextPermutation(seq, seqLen);

	for (int d : seq)
		std::cout << d;
	std::cout << std::endl;

	system("pause");
}
