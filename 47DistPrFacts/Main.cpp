#include <iostream>
#include <vector>

int euler47(const int nfacts, const int runlen, const int max) {
	std::vector<int> factors(max);

	int count = 0;
	for (int n = 2; n < max; ++n) {
		if (factors[n] == 0) {
			count = 0;
			for (int f = n; f < max; f += n) {
				++factors[f];
			}
		} else if (factors[n] == nfacts) {
			if (++count == runlen) {
				return n - runlen + 1;
			}
		} else {
			count = 0;
		}
	}

	return 0;
}

int main() {
	std::cout << euler47(4, 4, 1000000) << std::endl;
	system("pause");
}
