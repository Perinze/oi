T = int(input())
for _ in range(T):
	N = int(input())
	a = input()
	b = input()

	red = 0
	blue = 0
	for i in range(len(a)):
		if a[i] > b[i]:
			red += 1
		elif a[i] < b[i]:
			blue += 1

	if red > blue:
		print("RED")
	elif red < blue:
		print("BLUE")
	else:
		print("EQUAL")
