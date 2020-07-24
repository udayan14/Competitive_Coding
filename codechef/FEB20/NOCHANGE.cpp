#include<iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, p;
		cin >> n >> p;
		int a[n];
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		bool flag = false;
		int index = -1;
		for(int i=0 ; i<n ; i++){
			if(p%a[i]!=0){
				index = i;
				flag = true;
				break;
			}
		}
		if(flag){
			cout << "YES ";
			int out = (p/a[index]) + 1;
			for(int i=0 ; i<n ; i++){
				if(i==index)
					cout << out << " ";
				else
					cout << "0 ";
			}
			cout << "\n";
		}
		else{
			bool flag2 = false;
			int index2 = -1;
			for(int i=0 ; i<n-1 ; i++){
				if(a[i+1]%a[i]!=0){
					index2 = i;
					flag2 = true;
					break;
				}
			}
			if(flag2){
				cout << "YES ";
				int out = (p-a[index2+1])/a[index2] + 1;
				for(int i=0 ; i<n ; i++){
					if(i==index2){
						cout << out << " " << "1 ";
						++i;
					}
					else
						cout << "0 ";
				}
				cout << "\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
}
