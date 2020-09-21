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
		vector<ll> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		int pos_cnt = 0;
		int neg_cnt = 0;
		ll out = 0;
		for(int i=0 ; i<n ; i++){
			if(a[i]<0) neg_cnt++;
			else{
				pos_cnt++;
				out += a[i];
			}
		}
		if(out == 0){
			cout << "0\n";
			cout << "0\n";
			continue;
		}
		vector<int> out_index;
		
		int curr_neg = 0;
		int curr_pos = pos_cnt;
		for(int i=0 ; i<n ; i++){
			if(a[i] < 0){
				curr_neg++;
				out_index.push_back(i);	
			}
			else{
				curr_pos--;
			}
			if(curr_neg>=curr_pos){
					for(int j=i+1 ; j<n ; j++){
						if(a[j] >= 0) out_index.push_back(j);
					}
					break;
				}

		}
		cout << out << "\n";
		cout << out_index.size() << " ";
		for(auto e : out_index) cout << e+1 << " ";
		cout << "\n";
    }
    return 0;
}

