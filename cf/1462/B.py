

T = int(input())
for _ in range(T):
	n = int(input())
	s = input()

	sub = s[0:4]
#	print(sub)
	if sub == '2020':
		print("YES")
		continue

	sub = s[0:3] + s[-1]
#	print(sub)
	if sub == '2020':
		print("YES")
		continue

	sub = s[0:2] + s[-2:]
#	print(sub)
	if sub == '2020':
		print("YES")
		continue

	sub = s[0:1] + s[-3:]
#	print(sub)
	if sub == '2020':
		print("YES")
		continue

	sub = s[-4:]
#	print(sub)
	if sub == '2020':
		print("YES")
		continue

	print("NO")
