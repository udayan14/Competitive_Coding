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
vector<vector<ll>> dp;
int n, k;
ll find(int i, int j){
	if(dp[i][j]!=-1) return dp[i][j];

	if(j==1 || i==0){
		dp[i][j] = 1;
	}
	
	else{
		dp[i][j] = (find(i-1,j) + find(n-i,j-1)) % p;
	}

	return dp[i][j];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
		cin >> n >> k;
		if(k==1){
			cout << 1 << "\n";
			continue;
		}
		
		dp = vector<vector<ll>>(n+1,vector<ll>(k+1,-1));

		cout << find(n,k) << "\n";
    }
    return 0;
}

