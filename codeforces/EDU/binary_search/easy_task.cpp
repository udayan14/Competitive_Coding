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

inline bool isBad(int est_time, int copies, int t1, int t2){
	ll count = est_time/t1 + est_time/t2;
	return count < copies;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n,x,y;
		cin >> n >> x >> y;
		int out = min(x,y);
		n--;
		if(n==0){
			cout << out << "\n";
			continue;
		}
		int l = 0;
		int r = 1;
		while(isBad(r,n,x,y)) r <<= 1;

		while(r-l>1){
			double m = (l+r)/2;
			if(isBad(m,n,x,y)) l = m;
			else r = m;
		}
		cout << out + r << "\n";
    }
    return 0;
}

