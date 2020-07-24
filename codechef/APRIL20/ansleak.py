import numpy as np;
from sys import stdin, stdout
def main():
    t = int(input())
    for _ in range(t):
        n,m,k = map(int,input().split())
        data = np.zeros((n,k),dtype=np.int8)
        for i in range(n):
            data[i,:] = np.array([int(x) for x in input().split()])
        unique_eles = [0] * n
        counts = [0] * n
        base_solution = [0] * n
        for i in range(n):
            unique_eles[i], counts[i] = np.unique(data[i,:],return_counts=True)
            base_solution[i] = unique_eles[i][np.argmax(counts[i])]
        print(*base_solution,sep='\n')
main()
