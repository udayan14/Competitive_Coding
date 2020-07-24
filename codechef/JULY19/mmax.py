t = int(input())
for i in range(0,t):
    n = int(input())
    k = int(input())
    rem = k % n
    output = 2 * min(rem,n-rem)
    if(rem==n-rem):
        print(output-1)
    else:
        print(output)
