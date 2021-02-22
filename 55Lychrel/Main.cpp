#include <iostream>

constexpr int limit = 10000;

int reverse(int num) {
	int rev = 0;
	do {
		rev = rev * 10 + num % 10;
		num /= 10;
	} while (num != 0);

	return rev;
}

bool palindrome(int num) {
	return num == reverse(num);
}

int main() {
	int count = 0;
	bool lychrel[limit] {/*TODO:fill with trues*/};

	for (int n = limit - 1; n > 0; --n) {
		if (!lychrel[n]) {
			int next = n;
			for (int i = 0; i < 50; ++i) {
				next += reverse(next);

				// TODO: ???
				if (lychrel[next] || palindrome(next)) {
					lychrel[n] = false;
					break;
				}
			}

			//
		}
	}

	std::cout << count << std::endl;
}