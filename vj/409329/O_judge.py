import os

for i in range(1000000):
	if i % 2 != 0 and i % 5 != 0:
		for j in range(1, 10):
			os.system('echo "testing {} {}": >> O.out'.format(i, j))
			os.system('echo "{} {}" | ./O >> O.out'.format(i, j))
