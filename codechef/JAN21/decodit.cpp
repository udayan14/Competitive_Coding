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
		string s;
		cin >> s;

		int k = n/4;
		string out(k,'a');

		for(int i=0 ; i<k ; i++){
			int temp = 0;
			temp += 8*(s[4*i] - '0');
			temp += 4*(s[4*i + 1] - '0');
			temp += 2*(s[4*i + 2] - '0');
			temp += 1*(s[4*i + 3] - '0');

			out[i] = temp + 'a';
		}
		cout << out << "\n";
    }
    return 0;
}

