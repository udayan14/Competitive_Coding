#include<iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		unsigned even = 0;
		unsigned odd = 0;
		for(int i=0 ; i<n ; i++){
			unsigned in;
			cin >> in;
			if((__builtin_popcount(in)%2)==0)
				even++;
			else
				odd++;
		}
		while(q--){
			unsigned in;
			cin >> in;
			if((__builtin_popcount(in)%2)==0)
				cout << even << " " << odd << "\n";
			else
				cout << odd << " " << even << "\n";
		}
	}
}
