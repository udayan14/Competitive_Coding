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
        int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(int i=0 ; i<m ; i++) cin >> b[i];

		vector<short> reachable(1<<20,0); // denotes frontier as well as reached states;

		stack<int> s;
		s.push(0);
		reachable[0] = 1;
		while(!s.empty()){
			int curr = s.top();
			s.pop();
			for(auto x : a){
				if(reachable[x | curr]==0){
					s.push(x | curr);
					reachable[x | curr] = 1;
				}
			}
			for(auto x : b){
				if(reachable[x & curr]==0){
					s.push(x & curr);
					reachable[x & curr] = 1;
				}
			}
		}
		int out = 0;
		for(auto v : reachable) out += v;

		cout << out << "\n";
    }
    return 0;
}

