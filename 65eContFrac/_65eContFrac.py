def getSeqTerm(n):
	if n % 3 == 0:
		return n // 3 * 2
	elif n == 1:
		return 2
	else:
		return 1

def sumDigits(n):
	sum = 0
	while n > 0:
		sum += n % 10
		n //= 10

	return sum

def euler65(lastN):
	num, den = getSeqTerm(lastN), 1
	for x in range(lastN - 1, 0, -1):
		num, den = den + getSeqTerm(x) * num, num

	return sumDigits(num)

if __name__ == "__main__":
	print(euler65(100))