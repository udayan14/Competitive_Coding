t = int(input())
for i in range(t):
    n = int(input())
    n = n-1
    roundc = n//26
    output = pow(2,roundc)
    rem = n%26
    if rem<2:
        print(output,0,0)
    elif rem<10:
        print(0,output,0)
    else:
        print(0,0,output)
