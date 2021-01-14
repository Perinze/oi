N = -1

def bfs():
	q = [1]
	while len(q):
		num = q.pop(0)
		if num % N == 0:
			print(num)
			return
		q.append(num * 10)
		q.append(num * 10 + 1)

if __name__ == '__main__':
	while True:
		N = int(input())
		if N == 0:
			break
		bfs()
