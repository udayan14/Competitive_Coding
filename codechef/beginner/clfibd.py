from collections import Counter
t = int(input())
for i in range(0,t):
    s = input()
    c = Counter(s)
    l = list(c.values())
    l.sort()
    # print(l)
    flag = False
    if len(l) < 3:
        print("Dynamic")
    else:
        if len(l)>3 and l[3]!=l[2] + l[1]:
            l[0],l[1] = l[1],l[0]
        for j in range(2,len(l)):
            if l[j]!=l[j-1] + l[j-2]:
                print("Not")
                flag = True
                break
        if not flag:
            print("Dynamic")

