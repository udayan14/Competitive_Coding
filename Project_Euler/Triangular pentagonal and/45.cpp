#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPentagonal(long long int pn){
	double n = (sqrt(1.0 + 24*pn) + 1) / 6;
	if(n-int(n)==0.0)
		return true;
	return false;
}


int main() {
	long long int N;
	int a, b;
	cin >> N >> a >> b;
	if(a==3){
		long long int tn = 1;
		for (int i = 2; ; ++i)
		{
			if (tn >= N) break;
			if(isPentagonal(tn))
				cout << tn << endl;
			tn+=i;
		}
	}else if(a==5){
		long long int hn = 1;
		for (int i = 2; ; i=i+2)
		{
			if (hn >= N) break;
			if(isPentagonal(hn))
				cout << hn << endl;
			hn += 2*i + 1;
		}
	}
    return 0;
}
