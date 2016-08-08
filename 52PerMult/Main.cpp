#include <vector>
#include <iostream>

class Digits
{
	std::vector<int> digits;

public:
	void reset(int n)
	{
		digits.clear();

		while (n)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
	}

	bool contains(const Digits& other) const
	{
		if (digits.size() != other.digits.size())
			return false;

		for (int digit : digits)
		{
			bool found = false;
			for (int otherDigit : other.digits)
			{
				if (digit == otherDigit)
				{
					found = true;
					break;
				}
			}

			if (!found)
				return false;
		}

		return true;
	}
};

int main()
{
	Digits digitsA, digitsB;
	int x;

	for (int n = 1; ; ++n)
	{
		digitsA.reset(n * 2);
		digitsB.reset(n * 3);
		if (!digitsA.contains(digitsB))
			continue;

		digitsA.reset(n * 4);
		if (!digitsA.contains(digitsB))
			continue;

		digitsB.reset(n * 5);
		if (!digitsA.contains(digitsB))
			continue;

		digitsA.reset(x = n * 6);
		if (!digitsA.contains(digitsB))
			break;
	}

	std::cout << x << std::endl;
	system("pause");
}