#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// call by reference is used in x 
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


//const ll p = 1000000007;

int get_answer(int pos, int first, int last, int n){
	if(first==last){
		int out = 1 + abs(pos - first);
		if(first==n) out--;
		return out;
	}
	if( pos >= first && pos < last) return 0;
	if(pos < first) return first - pos;
	if( pos >= last) return pos - last + 1;
	else return 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll n, x, p, k;
		cin >> n >> x >> p >> k;
		p--;
		k--;
		vector<ll> a(n);
		for(int i=0 ; i < n ; i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		int start = distance(a.begin(),lower_bound(a.begin(),a.end(),x));
		int last = distance(a.begin(),upper_bound(a.begin(),a.end(),x));
		int out = 0;
		if(start == last){
			a[k] = x;
			sort(a.begin(),a.end());
			start = distance(a.begin(),lower_bound(a.begin(),a.end(),x));
			last = distance(a.begin(),upper_bound(a.begin(),a.end(),x));
			out++;
		}
		if(a[p]==x){
			cout << out << "\n";
			continue;
		}
		if(p > k){
			if(x < a[p]){
				cout << "-1\n";
				continue;
			}	
			else{
				cout << out + get_answer(p,start,last,n) << "\n";
			}
		}
		else if(p < k){
			if(x > a[p]){
				cout << "-1\n";
				continue;
			}
			else{
				cout << out + get_answer(p,start,last,n) << "\n";
			}
		}
		else{
				cout << out + get_answer(p,start,last,n) << "\n";
		}
    }
    return 0;
}

