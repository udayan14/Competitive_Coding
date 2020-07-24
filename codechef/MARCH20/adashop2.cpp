#include<iostream>

using namespace std;

int main(){
	pair<int,int> a[] = {{1,1},{8,8},{7,7},{8,6},{3,1},{1,3},{6,8},{5,7},{8,4},{5,1},{1,5},{4,8},{3,7},{8,2},{7,1},{1,7},{2,8}};
	int len = 17;
	int t;
	cin >> t;
	while(t--){
		int r0,c0;
		cin >> r0 >> c0;
		if(r0==1 && c0==1){
			cout << len-1 << "\n";
			for(int i=1 ; i<len ; i++)
				cout << a[i].first << " " << a[i].second << "\n";
		}
		else if(r0==c0){
			cout << len << "\n";
			for(int i=0 ; i<len ; i++)
				cout << a[i].first << " " << a[i].second << "\n";

		}
		else{
			cout << len+1 << "\n";
			int avg = (c0+r0)/2;
			cout << avg << " " << avg << "\n";
			for(int i=0 ; i<len ; i++)
				cout << a[i].first << " " << a[i].second << "\n";

		}
	}
}
