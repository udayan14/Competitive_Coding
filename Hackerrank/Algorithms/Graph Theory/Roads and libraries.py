#!/bin/python3
import queue
def roadsAndLibraries(n, c_lib, c_road, cities):
    # Complete this function
    if c_road >= c_lib:
        return c_lib * n
    else:
        comp = 0
        visited = [False]*(n+1)
        for c in range(1,n+1):
            # print(c)
            if(not visited[c]):
                comp = comp + 1
                q = queue.Queue(maxsize = 10**5)
                q.put(c)
                visited[c] = True
                while(not q.empty()):
                    w = q.get()
                    l = [x for x in cities if w in x]
                    l1 = [x[0] for x in l if x[1] == w] + [x[1] for x in l if x[0] == w]
                    for x in l1:
                        if not visited[x]:
                            visited[x] = True
                            q.put(x)
                        
        return len(cities)*c_road + (c_lib-c_road)* comp
if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        n, m, c_lib, c_road = input().strip().split(' ')
        n, m, c_lib, c_road = [int(n), int(m), int(c_lib), int(c_road)]
        cities = []
        for cities_i in range(m):
           cities_t = [int(cities_temp) for cities_temp in input().strip().split(' ')]
           cities.append(cities_t)
        result = roadsAndLibraries(n, c_lib, c_road, cities)
        print(result)

