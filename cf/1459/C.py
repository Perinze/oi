def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

tmp = input()
N = tmp.split(' ')[0]
M = tmp.split(' ')[1]

a = input().split(' ')
b = input().split(' ')

a.sort()
mina = a[0]
for i in range(len(a)):

