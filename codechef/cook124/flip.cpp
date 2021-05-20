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
    	string a, b;
		cin >> a >> b;
		int n = a.length();
		int out = 0;
		bool f1 = false;
		bool f2 = false;
		for(int i=0 ; i<n ; i++){
			if(i&1){
				if (f1){
					if(a[i]==b[i]){
						f1 = false;
						out++;
					}
					else continue;
				}
				else{
					if(a[i]==b[i]){
						continue;
					}
					else{
						f1 = true;
					}
				}
			}
			else{
				if (f2){
					if(a[i]==b[i]){
						f2 = false;
						out++;
					}
					else continue;
				}
				else{
					if(a[i]==b[i]){
						continue;
					}
					else{
						f2 = true;
					}
				}
			}
		}
		if(f1) out++;
		if(f2) out++;
		cout << out << "\n";
    }
    return 0;
}

