#include<iostream>
#include<map>
#include<limits>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int a[n];
		int b[n];
		for(int i=0 ; i<n ; i++)
			cin >> a[i];
		for(int i=0 ; i<n ; i++)
			cin >> b[i];
		map<int,int> count;
		for(int i=0 ; i<n ; i++)
			count[a[i]] += b[i];
		int output = 20000;
		for(auto &kvpair : count){
			if(kvpair.second < output)
				output = kvpair.second;
		}
		cout << output << "\n";
	}
}
