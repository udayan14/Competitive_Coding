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
		string s;
		cin >> s;
		int out1 = 0;
		for(int i=1 ; i<n ; i++){
			if(s[i]=='1' && s[i-1]=='1') out1++;
		}
		int out2 = 0;
		for(int i=1 ; i<n ; i++){
			if(s[i]=='0' && s[i-1]=='0') out2++;
		}
		
		cout << max(out1,out2) << "\n";
    }
    return 0;
}

