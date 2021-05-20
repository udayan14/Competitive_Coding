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
int d;

inline bool isGood(double opt_val, int n, const vector<int>& a, int &first, int& last){
	vector<double> temp(n);
	vector<double> sum_vec(n);
	vector<double> min_vec(n);
	vector<int> min_ind(n);
	for(int i = 0 ; i<n ; i++){
		temp[i] = (double)a[i] - opt_val;
	}

	sum_vec[0] = temp[0];
	min_vec[0] = 0.0;
	min_ind[0] = 0;

	for(int i=1 ; i<n ; i++){
		sum_vec[i] = sum_vec[i-1] + temp[i];
		if(min_vec[i-1] < sum_vec[i-1]){
			min_vec[i] = min_vec[i-1];
			min_ind[i] = min_ind[i-1];
		}
		else{
			min_vec[i] = sum_vec[i-1];
			min_ind[i] = i;
		}
	}
	
	for(int i=d-1 ; i<n ; i++){
		if(sum_vec[i] >= min_vec[i-d+1]){
			first = min_ind[i-d+1];
			last = i;
			return true;
		}
	}
	return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
		int n;
		cin >> n >> d;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		int first, last;

		double l = 0;
		double r = 101;
		
		int count = 100;
		while(count--){
			double m = (l+r)/2.0;
			if(isGood(m,n,a,first,last)) l = m;
			else r = m;
		}
		//cout << "OPT_VAL: " << l << "\n";
		cout << first+1 << " " << last+1 << "\n";
    }
    return 0;
}

