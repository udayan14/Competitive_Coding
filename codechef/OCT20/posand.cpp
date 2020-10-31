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
        int n;
		cin >> n;
		if(n==1){
			cout << "1\n";
			continue;
		}
		if((n&(n-1))==0){
			cout << "-1\n";
			continue;
		}
		else{
			int curr = 1;
			vector<int> out;
			while(2*curr < n){
				for(int e = 2*curr-1 ; e >= curr ; e--) out.push_back(e);
				curr <<= 1;
			}
			reverse(out.begin(),out.end());
			for(int e = curr+1 ; e <= n ; e++) out.push_back(e);
			out.push_back(curr);
			for(auto e : out) cout << e << " ";
			cout << "\n";
		}
    }
    return 0;
}

