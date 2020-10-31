#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template<typename T, typename U> 
static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
} 
  
// call by reference is used in x 
template<typename T, typename U> 
static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}


const long long int p = 1000000007;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll n, k;
		cin >> n >> k;
		vector<ll> q(n);
		for(int i=0 ; i<n ; i++) cin >> q[i];
		ll day = 1;
		ll carry = 0;
		bool found = false;
		while(!found && day <= n){
			if(q[day-1] + carry < k){
				found = true;
				carry = 0;
				break;
			}
			carry += q[day-1] - k;
			day++;
		}
		if(found){
			cout << day << "\n";
			continue;
		}
		if(carry%k==0)
			day += carry/k;
		else
			day += carry/k;

		cout << day << "\n";
		continue;
    }
    return 0;
}

