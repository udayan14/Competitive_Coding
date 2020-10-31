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
	int max_val = 1e5;
    while(t--){
        ll d;
		cin >> d;

		if(d==0){
			cout << "1\n1\n";
			continue;
		}

		if(d + 2 <= max_val){
			cout << "2\n";
			cout << d+2 << " " << d+1 << "\n";
			continue;
		}
		vector<int> out;
		out.push_back(max_val);
		while(d > max_val-2){
			out.push_back(max_val-1);
			d -= max_val-2;
		}
		if(d){
			out.push_back(1);
			out.push_back(d+1);
			out.push_back(d+2);
		}
		cout << out.size() << "\n";
		for(auto e: out) cout << e << " ";
		cout << "\n";
    }
    return 0;
}

