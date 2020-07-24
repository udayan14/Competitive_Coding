#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstring>
using namespace std;
#define INT_MAX 5e4

int main() {
	int n,q;
	cin >> n >> q;
	int a[n+1];
	memset(a,0,sizeof(a));  
	while(q--){
		// for (int i = 0; i < n+1; ++i)
		// {
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		int k;
		cin >> k;
		if(k==1){
			int l,r,val;
			cin >> l >> r >> val;
			if(val!=0){
				for (int i = l; i <= r ; ++i)
				{
					a[i] = a[i]^val;
				}
			}
		}
		else if(k==2){
			int l,r;
			cin >> l >> r;
			int prev = -1;
			int out = INT_MAX + 1;
			for (int i = l; i <= r; ++i)
			{
				if(a[i]==1){
					if(prev==-1){
						prev = i;
						// cout << i <<"-"<<prev<<endl;
					}
					else{
						if(i-prev < out)
							out = i-prev;
						//cout << out << endl;
						prev = i;
					}
				}
			}
			if(out==INT_MAX + 1)
				cout<<-1<<endl;
			else cout << out << endl;
		}
		else if(k==3){
			int l,r;
			cin >> l >> r;
			bool ls=false;
			bool rs=false;
			while(l!=r){
				if(a[l]==1)
					ls=true;
				if(a[r]==1)
					rs=true;
				if(!ls)
					l++;
				if(!rs)
					r--;
				if(ls && rs)
					break;
			}
			if(r-l==0)
				cout << -1 << endl;
			else cout << r-l << endl;
		}
	}
    return 0;
}
