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

bool isGood(int count, const string &t, const string &p, const vector<int> &perm){
	//cout << count << "*\n";
	int n = t.size();
	amin(count,t.length());
	vector<bool> mask(n,true);
	for(int i=0 ; i<count ; i++){
		mask[perm[i]] = false;
	}
	
	int itr = 0;
	for(int i=0 ; i<n && itr < p.length(); i++){
		if(!mask[i]) continue;
		if(t[i]!=p[itr]) continue;
		else itr++;
	}
	if(itr==p.length()) return true;
	else return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        string a, b;
		cin >> a >> b;
		int n = a.length();
		vector<int> p(n);
		for(int i=0 ; i<n ; i++){
			int in;
			cin >> in;
			p[i] = in-1;
		}
		int l = 0;
		int r = 1;
		while(isGood(r,a,b,p)){
			//cout << "r_val good : " << r << "\n";
			r <<= 1;
		}

		while(r-l > 1){
			int m = (l+r)/2;
			if(isGood(m,a,b,p)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

