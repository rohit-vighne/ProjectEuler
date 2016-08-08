#include <iostream>
//#include <cstdlib>

/*
const int coins[] = { 200, 100, 50, 20, 10, 5, 2, 1 };
const int numCoins = sizeof(coins) / sizeof(*coins);

int countWays(int amount, std::size_t i = 0)
{
	if (amount == 0)
		return 1;

	int count = 0;

	for (; i < numCoins; ++i)
	{
		int coinVal = coins[i];
		if (coinVal <= amount)
			count += countWays(amount - coinVal, i);
	}

	return count;
}
*/

int main(int argc, char* argv[])
{
	const int amount = 200;
	const int coins[] = { 200, 100, 50, 20, 10, 5, 2, 1 };

	int cache[amount + 1] = { 1 };
	for (auto coin : coins)
		for (int i = coin; i <= amount; ++i)
			cache[i] += cache[i - coin];

	std::cout << cache[amount] << std::endl;
	system("pause");

	/*
	std::cout << countWays(amount) << std::endl;
	system("pause");
	*/
}