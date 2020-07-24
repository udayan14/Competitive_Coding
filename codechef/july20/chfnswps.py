from collections import defaultdict

R = lambda: map(int, input().split())
t, = R()
for _ in range(t):
    n = R()
    map_a = R()
    map_b = R()
    a = list(map_a)
    b = list(map_b)
    min_a = min(a)
    min_b = min(b)
    all_min = min(min_a,min_b)
    all_count = defaultdict(int)
    A_count = defaultdict(int)
    B_count = defaultdict(int)
    for ele in a:
        all_count[ele] += 1
        A_count[ele]   += 1
    for ele in b:
        all_count[ele] += 1
        B_count[ele]   += 1

    flag = True
    A_ex = []
    B_ex = []
    for k,v in all_count.items():
        if(v%2==1):
            flag = False
            break
        temp_a = A_count[k] - v//2
        temp_b = B_count[k] - v//2

        if temp_a > 0:
            A_ex += temp_a * [k]
        elif temp_b > 0:
            B_ex += temp_b * [k]

    if not flag:
        print(-1)
    else:
        output = 0
        A_ex.sort()
        B_ex.sort()
        l = len(A_ex)
        # print(A_ex,B_ex)
        for i in range(l):
            output += min(2*all_min,A_ex[i],B_ex[l-i-1])
        print(output)
