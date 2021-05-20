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

inline bool isGood(double t, const vector<double> &pos, const vector<double> &vel){
	//cout << t << "*\n";
	double max_min = pos[0] - t*vel[0];
	double min_max = pos[0] + t*vel[0];

	int n = pos.size();
	
	for(int i=1 ; i<n ; i++){
		amax(max_min, pos[i] - t*vel[i]);
		amin(min_max, pos[i] + t*vel[i]);
	}

	return max_min <= min_max;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
	cout.precision(10);

    int t;
	t = 1;

    while(t--){
        int n;
		cin >> n;
		vector<double> pos(n);
		vector<double> vel(n);

		for(int i=0 ; i<n ; i++){
			cin >> pos[i] >> vel[i];
		}

		double l = 0.0;
		double r = 1.0;
		while(!isGood(r,pos,vel)) r *= 2.0;

		for(int i=0 ; i<100 ; i++){
			double m = (l+r)/2;
			if(!isGood(m,pos,vel)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

