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
		string s;
		cin >> n >> s;
		// n 1 1
		// n 2 2
		// n 3 1
		// n 4 
		bool all_even_raze = true;
		bool all_odd_bree = true;
		for(int i=0 ; i<n ; i++){
			if((i+1)&1){
				if((s[i]-'0')%2==1)
					all_even_raze = false;
			}
			else{
				if((s[i]-'0')%2==0)
					all_odd_bree = false;
			}
		}
		if((n%2==1) && !all_even_raze){
			cout << "1\n";
		}
		else if(n%2==1)
			cout << "2\n";
		else if((n%2==0) && all_odd_bree){
			cout << "1\n";
		}
		else{
			cout << "2\n";
		}
    }
    return 0;
}

