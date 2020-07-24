#include<iostream>
#include<limits.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		unsigned long long int a[n];
		for(int i=0 ; i<n ; ++i)
			cin >> a[i];
		unsigned long long int fwd[n];
		unsigned long long int bwd[n];
		fwd[0] = a[0] % k;
		for(int i=1 ; i<n ; ++i)
			fwd[i] = (fwd[i-1] + a[i])%k;
		bwd[n-1] = 0;
		for(int i=n-2 ; i>=0 ; --i){
			bwd[i] = bwd[i+1] + (k - (a[i+1]%k))%k;
		}
		long long int curr_min = INT_MAX;
		for(int i=0 ; i<n ; ++i){
			if(fwd[i]>=bwd[i] && fwd[i]-bwd[i]<=curr_min){
				curr_min = fwd[i] - bwd[i];
			}
		}
		cout << curr_min << "\n";
	}
}
