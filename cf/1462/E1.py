
import math

def P(n):
	return n * (n - 1) * (n - 2) // 6;

T = int(input())
for _ in range(T):
	n = int(input())
	a = list(map(int, input().split()))
	ans = 0
	a.sort()
	l = 0
	r = 0
	while l < n - 2:
		while a[r] - a[l] <= 2 and r < n - 1:
			r += 1
		if a[r] - a[l] > 2:
			r -= 1
#		print(l, r)
		if (r - l >= 2):
			ans += P(r - l + 1)
		l += 1

	print(ans)
