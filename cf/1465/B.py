T = int(input())
for _ in range(T):
	line = input()
	num = int(line)
	OK = False
	while not OK:
		OK = True
		for i in range(len(line)):
			digit = int(line[i])
			if digit == 0:
				continue
			if num % digit:
				OK = False
				num += 1
				line = str(num)
				break
	print(num)
