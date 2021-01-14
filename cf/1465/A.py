T = int(input())
for _ in range(T):
	n = int(input())
	line = input()
	a = 0
	b = 0
	flag = True
	for i in reversed(range(len(line))):
		if flag and line[i] != ')':
			flag = False
		if flag:
			b += 1
		else:
			a += 1
			
	if b > a:
		print("YES")
	else:
		print("NO")
