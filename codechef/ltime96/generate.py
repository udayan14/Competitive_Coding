import random
t = 100
print(t)

for i in range(t):
    x = random.randrange(1,10000000000)
    y = random.randrange(1,10000000000)
    if(x < y):
        print(x,y)
    else:
        print(y,x)
