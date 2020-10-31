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
	t = 1;

    while(t--){
        int n;
		cin >> n;
		vector<ll> weights(n);
		ll sum = 0;
		for(int i=0 ; i<n ; i++){
			cin >> weights[i];
			sum += weights[i];
		}
		int max_num = (1 << n);
		ll output = LLONG_MAX;
		for(int bit_mask = 0 ; bit_mask < max_num ; bit_mask++){
			ll temp = 0;
			for(int i=0 ; i<n ; i++){
				if(bit_mask&(1<<i)) temp += weights[i];
			}
			ll curr_ans = sum - 2*temp;
			if(curr_ans < 0) curr_ans *= -1;
			amin(output,curr_ans);
		}
		cout << output << "\n";
    }
    return 0;
}

