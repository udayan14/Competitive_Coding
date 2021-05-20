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
		else if(a[mid] > x) last = mid;
		else if(a[mid] < x) first = mid;
	}
	if(a[first]<=x) return 1 + first;
	return first;
} 

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n, k;
		cin >> n;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		cin >> k;
		while(k--){
			int l,r;
			cin >> l >> r;
			int id1 = find_left(a,l-1);
			int id2 = find_left(a,r);
			cout << id2 - id1 << " ";
		}
		cout << "\n";
    }
    return 0;
}

