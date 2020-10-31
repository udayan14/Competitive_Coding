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
		int n = s.length();

		vector<int> count(26,0);
		for(int i=0 ; i<n ; i++){
			count[s[i]-'A']++;
		}
		string output;
		bool possible = true;
		int odd_count = 0;
		char odd_char;
		for(int i=0 ; i<26 ; i++){
			if(count[i]&1){
				if(odd_count)
					possible = false;
				else{
					odd_count++;
					odd_char = (char)('A' + (char)i);
					for(int j=0 ; j<count[i]/2 ; j++) output.push_back(odd_char);
				}
			}
			else{
				char c = (char)('A' + (char)i);
				for(int j=0 ; j<count[i]/2 ; j++) output.push_back(c);
			}
		}
		if(possible){
			cout << output;
			if(odd_count) cout << odd_char;
			reverse(output.begin(), output.end());
			cout << output << "\n";
		}
		else{
			cout << "NO SOLUTION\n";
		}
    }
    return 0;
}

