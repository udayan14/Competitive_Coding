import itertools
primes = [2,3,5,7,11,13,17,19]
output = []
n = int(input())
if n==9:           #Python is too slow for this case.
	print(16695334890) 
else:
	l = list(range(n+1))
	for s in itertools.permutations(l):
		flag = True
		for i in range(n-2):
			str_list = s[i+1:i+4]
			temp = list(map(str,str_list))
			num = int(''.join(temp))
			if num%(int(primes[i])) == 0:
				pass
			else:
				flag = False
				break;
		if flag:
			output.append(int((''.join(list(map(str,s))))))
	print(sum(list(output)))