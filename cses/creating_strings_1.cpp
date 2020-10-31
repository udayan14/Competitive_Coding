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
	t = 1;

    while(t--){
        string s;
		cin >> s;
		vector<string> out;

		sort(s.begin(),s.end());
		out.push_back(s);
		while(next_permutation(s.begin(),s.end())){
			out.push_back(s);
		}

		cout << out.size() << "\n";
		for(auto str : out) cout << str << "\n";
    }
    return 0;
}

