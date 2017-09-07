#include <iostream>
#include <vector>

using Sieve = std::vector<int>;

Sieve makeSieve(const int max) {
	Sieve sieve(max, true);

	int sum = 0;
	for (int n = 2; n < max; ++n) {
		if (sieve[n]) {
			if ((sum += n) > max) {
				break;
			}

			for (int f = n + n; f < max; f += n) {
				sieve[f] = false;
			}
		}
	}

	return sieve;
}

int euler50(const Sieve sieve) {
	const int max = sieve.size();

	int max_length = 0;
	int winner;

	for (int start = 2;;) {
		int sum = 0, length = 0;
		for (int n = start; (sum + n) < max; ++n) {
			if (sieve[n]) {
				sum += n;
				++length;
				if (sieve[sum] && length > max_length) {
					winner = sum;
					max_length = length;
				}
			}
		}

		do {
			++start;

			if (start >= max) {
				return winner;
			}
		} while (!sieve[start]);
	}
}

int main() {
	std::cout << euler50(makeSieve(1000000)) << std::endl;
	system("pause");
}