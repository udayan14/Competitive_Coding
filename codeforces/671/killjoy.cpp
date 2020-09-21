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
		ll n, x;
		cin >> n >> x;
	   
		vector<ll> a(n);
		ll sum = 0;
		bool all_inf = true;
		ll init_inf = 0;
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
			sum += a[i];
			if(a[i]!=x) all_inf = false;
			else init_inf++;
		}
	
		ll tbc = n - init_inf;

		if(all_inf){
			cout << "0\n";
			continue;
		}
		if(sum == n * x || tbc==1 || init_inf > 1){
			cout << "1\n";
			continue;
		}
		
		bool flag = true;
		if(init_inf==1){

			for(int i=0 ; i<tbc-1 && flag; i++){
				if((sum-(1+i)*x) % (tbc-i) == 0)
					flag = false;
			}
			if(!flag){
				cout << "1\n";
				continue;
			}
		}

		else{
			cout << "2\n";
			continue;
		}
    }
    return 0;
}

