#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		unsigned a[n];
		unsigned b[n];
		for(int i=0 ; i<n ; i++)
			cin >> a[i];
		for(int i=0 ; i<n ; i++)
			cin >> b[i];
		sort(a,a+n);
		sort(b,b+n);
		unsigned long long int out = 0;
		for(int i=0 ; i<n ; i++)
			out += min(a[i],b[i]);
		cout << out << "\n";
	}
}
