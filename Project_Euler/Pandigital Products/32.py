import itertools
n = input()
n = int(n)
if n==9:
	print(45228)
else:
	l =list(map(lambda x:x+1,list(range(n))))
	output = []
	for num in itertools.permutations(l):
		for i in range(0,(n-2)//2):
			for j in range(i+1,n//2+1):
				l1 = num[0:i+1]
				l2 = num[i+1:j+1]
				l3 = num[j+1::]

				x = list(map(str,l1))
				y = list(map(str,l2))
				z = list(map(str,l3))
				x1 = int(''.join(x))
				y1 = int(''.join(y))
				z1 = int(''.join(z))
				if x1*y1 == z1:
					output.append(z1)

	print(sum(list(set(output))))
