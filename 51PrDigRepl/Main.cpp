#include <iostream>

int digits(int d) {
	int n = 1;
	while (--d > 0) {
		n *= 10;
	}

	return n;
}

int main() {
	for (int d = 5; d <= 5; ++d) {
		const int t = digits(d); // 10000

		for (int a = 0; a < d; ++a) {
			//
		}
	}
}