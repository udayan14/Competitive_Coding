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

int find_left(const vector<int> &a, int x){
	int first = 0;
	int last = (int)a.size();
	while(last-first>1){
		int mid = (first + last) / 2;
		if(a[mid]==x) first = mid;
		if(a[mid] > x) last = mid;
		else first = mid;
	}
	return first;
} 

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		while(k--){
			int in;
			cin >> in;
			int out = find_left(a,in);
			if(a[out] <= in) cout << out+1 << "\n";
			else cout << 0 << "\n";
		}
    }
    return 0;
}

