#include <iostream>
using namespace std;

int main()
{
	for (int n = 45; n < 141; ++n)
	{
		const int tri = n * (n + 1) / 2;
		for (int n = 32; n < 100; ++n)
		{
			const int squ = n * n;
			for (int n = 26; n < 82; ++n)
			{
				const int pen = n * (3 * n - 1) / 2;
				for (int n = 23; n < 71; ++n)
				{
					const int hex = n * (2 * n - 1);
					for (int n = 21; n < 64; ++n)
					{
						const int hep = n * (5 * n - 3) / 2;
						for (int n = 19; n < 59; ++n)
						{
							const int oct = n * (3 * n - 2) / 2;

							if (tri % 100 == squ / 100 &&
								squ % 100 == pen / 100 &&
								pen % 100 == hex / 100 &&
								hex % 100 == hep / 100 &&
								hep % 100 == oct / 100 &&
								oct % 100 == tri / 100)
							{
								cout << tri + squ + pen + hex + hep + oct << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
}