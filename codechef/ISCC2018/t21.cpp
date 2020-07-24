#include<iostream>
#include<string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string m,n;
		cin >> m >> n;
		int out1 = 0;
		int out2 = 0;
		for(int i=0 ; i<m.length() ; i++)
			out1+=m[i]-'0';
		for(int i=0 ; i<n.length() ; i++)
			out2+=n[i]-'0';
		cout << ((out1%3)*(out2%3))%3 << "\n"; 

	}
}
