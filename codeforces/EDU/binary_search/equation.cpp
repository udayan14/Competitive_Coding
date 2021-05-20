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

bool isBad(double val, double c){
	return val*val + sqrt(val) < c;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        double c;
		cin >> c;
		cout.precision(10);
		double l = 0.0;
		double r = 1.0;
		while(isBad(r,c)) r*=2.0;
		//cout << r << "*\n";

		for(int i=0 ; i<100 ; i++){
			double m = (l+r)/2.0;
			if(isBad(m,c)){
				l = m;
			}
			else r = m;
		}
		cout << r << "\n";
		
    }
    return 0;
}

