#include "ExpData.h"

#include <cstddef>
#include <cmath>
#include <iostream>

int main()
{
	double highestVal = 0.0;
	std::size_t highestI;

	for (std::size_t i = 0; i < nVals; i += 2)
	{
		int base = vals[i];
		int exp = vals[i + 1];

		double compVal = exp * std::log(base);
		if (compVal > highestVal)
		{
			highestVal = compVal;
			highestI = i;
		}
	}

	std::cout << "Line " << (highestI / 2 + 1) << " has the highest value" << std::endl;
	system("pause");
}