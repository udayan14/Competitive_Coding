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
        long long n, k, x, y;
		cin >> n >> k >> x >> y;

		if(x==y){
			cout << n << " " << n << "\n";
			continue;
		}

		int temp = k%4;

		if(x > y){
			if(temp==1){
				cout << n << " " << y + n - x << "\n";
			}
			else if(temp==2){
				cout << n - x + y << " " << n << "\n";
			}
			else if(temp==3){
				cout << 0 << " " << x - y << "\n";
			}
			else{
				cout << x - y << " " << 0 << "\n";
			}
		}
		else{
			if(temp==1){
				cout << x + n - y << " " << n << "\n";
			}
			else if(temp==2){
				cout << n << " " << n - y + x << "\n";
			}
			else if(temp==3){
				cout << y-x << " " << 0 << "\n";
			}
			else{
				cout << 0 << " " << y - x << "\n";
			}
		}
    }
    return 0;
}

