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
		vector<int> a(n);
		int sum = 0;
		for(int i=0 ; i<n ; i++){ 
			cin >> a[i];
			sum += a[i];
		}
		if(sum==0){
			cout << "NO\n";
			continue;
		}
		if(sum > 0)
			sort(a.begin(), a.end(), greater<int>());
		else
			sort(a.begin(),a.end());
		cout << "YES\n";
		for(auto e : a) cout << e << " ";
		cout << "\n";

    }
    return 0;
}

