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
		vector<int> count(n+1,0);
		int in;
		for(int i=0 ; i<n ; i++){
			cin >> in;
			count[in]++;
		}
		vector<short> free(2*n,0);
		int out = 0;
		while(true){
			bool exit = true;

			for(int i=1 ; i<=n ; i++){
				if(count[i]>0){
					exit = false;
					int fwd = 0;
					int bwd = 0;
					while(free[i+fwd]==1){
						fwd++;
					}
					while(i-bwd>0 && free[i-bwd]==1){
						bwd++;
					}
					int temp = fwd;
					if(i-bwd>0 && free[i-bwd]==0){
						if(bwd <= fwd){
							out += bwd;
							free[i-bwd] = 1;
						}
						else{
							out += fwd;
							free[i+fwd] = 1;
						}
					}
					else{
						out += fwd;
						free[i+fwd] = 1;
					}

					count[i]--;
				}
			}
			if(exit) break;
		}
		cout << out << "\n";
    }
    return 0;
}

