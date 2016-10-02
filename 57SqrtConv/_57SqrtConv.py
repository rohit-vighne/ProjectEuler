from fractions import Fraction
from math import log10

if __name__ == '__main__':
	frac = Fraction(3, 2)
	count = 0

	for i in range(1000):
		frac = 1 + 1 / (1 + frac)
		if int(log10(frac.numerator)) > int(log10(frac.denominator)):
			count += 1

	print(count)