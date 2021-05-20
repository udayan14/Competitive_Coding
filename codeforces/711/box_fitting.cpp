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

int my_log2(int n){
	int out = 0;
	while((n&1)==0){
		out++;
		n >>= 1;
	}

	return out;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, W;
		cin >> n >> W;
		
		vector<int> counter(21,0);

		int in;
		vector<int> widths(n);
		for(int i=0 ; i<n ; i++){
			cin >> in;
			counter[my_log2(in)]++;
		}


		int out = 0;
		int curr_sum = 0;
		int assigned = n;
		while(assigned){
			for(int i=20 ; i>=0 ; i--){
				if(counter[i]==0) continue;
				while(counter[i]){
					int weight = (1<<i);
					if(curr_sum + weight > W){
						break;
					}
					else{
						curr_sum += weight;
						counter[i]--;
						assigned--;
					}
				}
				
			}
			out++;
			curr_sum = 0;
		}
		cout << out << "\n";
    }
    return 0;
}

