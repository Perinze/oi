

T = int(input())
for _ in range(T):
	x = int(input())
	if x > 45:
		print(-1)
		continue
	i = 9
	ans = 0
	k = 1
	while x > i:
		ans += i * k
		x -= i
		i -= 1
		k *= 10
	ans += x * k
	print(ans)
