#include <iostream>

#include <chrono>

static constexpr const int N = 100;

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	int ways[N + 1] {};
	ways[0] = 1;

	for (int n = 1; n < N; ++n) {
		for (int a = n; a <= N; ++a) {
			ways[a] += ways[a - n];
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::cout << ways[N] << std::endl;

	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;

	system("pause");
}
