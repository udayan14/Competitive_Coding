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

bool isGood(double ratio, const vector<int> &a, const vector<int> &b, int sz, int k){
	vector<double> temp(sz);
	for(int i=0 ; i<sz ; i++) temp[i] = a[i] - ratio*b[i];
	sort(temp.begin(),temp.end());
	double val = 0;
	for(int i=0 ; i<k ; i++) val += temp[sz-1-i];
	return val < 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
	cout.precision(10);
    int t;
	t = 1;

    while(t--){
        ll n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0 ; i<n ; i++) cin >> a[i] >> b[i];

		double l = 0;
		double r = 1.0;
		while(!isGood(r,a,b,n,k)){
			r *= 2.0;
		}
		for(int i=0 ; i<100 ; i++){
			double m = (r+l)/2;
			if(isGood(m,a,b,n,k)) r = m;
			else l = m;
		}
		cout << r << "\n";
    }
    return 0;
}

