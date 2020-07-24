#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int p[1000001];

bool isPentagonal(long long int pn,int N){
	double n = (sqrt(1.0 + 24*pn) + 1) / 6;
	if(n-int(n)==0.0 && n<N)
		return true;
	return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N , K;
    cin >> N >> K;
 	for(long long int i=0 ; i<1000001 ; i++){
 		p[i] = (i*(3*i-1))/2;
 	} 	
 	for(int i=K+1 ; i<N ; i++){
 		if(isPentagonal(p[i]+p[i-K],N) || isPentagonal(p[i]-p[i-K],N))
 			cout << p[i] << endl;
 	}
}
