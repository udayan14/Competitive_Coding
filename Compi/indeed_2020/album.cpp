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
		vector<int> count(26);
		int n = s.length();
		for(int i=0 ; i<n ; i++){
			count[s[i]-'A'] += (n-i); 
		}
		vector<vector<int>> count2(100000);
		vector<pair<int,char>> output;
		for(int i=0 ; i<26 ; i++){
			if(count[i] > 0){
				count2[count[i]].push_back(i);
			}
		}
		for(int i=100000-1 ; i>=0 ; i--){
			if(count2[i].size()>0){
				for(auto i : count2[i]){
					char out = 'A' + i;
					cout << out;
				}
			}
		}
		cout << "\n";
    }
    return 0;
}

