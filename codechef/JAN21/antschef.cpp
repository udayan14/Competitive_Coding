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
		vector<ll> total_count(n);
		vector<ll> pos(n,0);
		vector<ll> neg(n,0);
		vector<vector<int>> pos_position(n);
		vector<vector<int>> neg_position(n);
		vector<set<int>> pos_set(n);
		vector<set<int>
		map<int,int> count;
		map<int,int> contribution;
		for(int i=0 ; i<n ; i++){
			int m;
			cin >> m;
			total_count[i] = m;
			for(int j=0 ; j<m ; j++){
				ll in;
				cin >> in;
				if(in > 0){
					count[in]++;
					pos[i]++;
					pos_position[i].push_back(in);
				}
				else{
					count[-in]++;
					neg[i]++;
					neg_position[i].push_back(in);
				}
			}
			reverse(neg_position[i].begin(),neg_position[i].end());
		}

		ll out = 0;
		for(int i=0 ; i<n ; i++){
			out += pos[i] * neg[i];
		}

		//for(auto vec : pos_position){
			//for(auto ele : vec) cout << ele << " ";
			//cout << "\n";
		//}
		//for(auto vec : neg_position){
			//for(auto ele : vec) cout << ele << " ";
			//cout << "\n";
		//}
		
		for(auto &kvpair : count){
			if(kvpair.second > 1){
				out += contribution[kvpair.first] + 1;
			}
		}

		cout << out << "\n";
    }
    return 0;
}

