n = int(input())
if n % 2 == 0:
	print((n // 2 + 1) * (n // 2 + 1))
else:
	n = (n + 1) // 2
	print(2 * (n + 1) * n)
