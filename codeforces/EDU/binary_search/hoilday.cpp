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

bool isBad(int curr_time, int num_balloons, int n, const vector<int> &t, const vector<int> &z, const vector<int> &y, vector<int> &out){
	//cout << curr_time << "*\n";
	int count = 0;
	for(int i=0 ; i<n ; i++){
		int temp = curr_time / (t[i]*z[i] + y[i]);
		out[i] = temp * z[i];
		int rem = curr_time - temp * (t[i]*z[i] + y[i]);
		int temp2 = rem / t[i];
		amin(temp2,z[i]);
		out[i] += temp2;
		count += out[i];
	}
	return count < num_balloons;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int m,n;
		cin >> m >> n;
		vector<int> t(n), z(n), y(n), out(n,0);
		for(int i=0 ; i<n ; i++) cin >> t[i] >> z[i] >> y[i];

		if(m==0){
			cout << 0 << "\n";
			for(auto e : out) cout << e << " ";
			cout << "\n";
			continue;
		}
		int l = 0;
		int r = 1;
		while(isBad(r,m,n,t,z,y,out)) r <<= 1;

		while(r-l > 1){
			int mid = (r+l)/2;
			if(isBad(mid,m,n,t,z,y,out)) l = mid;
			else r = mid;
		}
		isBad(r,m,n,t,z,y,out);
		cout << r << "\n";
		int rem = m;
		for(auto balloon: out){
			if(balloon <= m){
				cout << balloon << " ";
				m -= balloon;
			}
			else{
				cout << m << " ";
				m = 0;
			}
		}
    }
    return 0;
}

