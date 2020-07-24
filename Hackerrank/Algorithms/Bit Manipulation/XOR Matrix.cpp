#include <iostream>

using namespace std;



int main(){
	int n;
	long long m;
	cin >> n >> m;
	int a[n];
	for(int i=0 ; i<n ; i++){
		int in;
		cin >> in;
		a[i] = in;
	}
	m--;
	long long i=1;
	for(; m/i ; i<<=1){
		if((m&i))
			for(int j=0 ; j<n ; j++)
				a[j] = a[j] ^ a[(j+i)%n];
	}
	for(int i=0 ; i<n ; i++){
		cout << a[i] << " ";
	}
}
