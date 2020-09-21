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
	t = 1;

    while(t--){
        int n;
		cin >> n;
		
		vector<ll> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];

		sort(a.begin(),a.end());

		//cout << (n-1)/2 << "\n";
		vector<ll> out1;
		vector<ll> out2;
		int temp = n;
		int start = 0;
		int end = n-1;
		while(temp>=2){
			out1.push_back(a[end--]);
			out2.push_back(a[start++]);
			temp-=2;
		}
		if(temp) out1.push_back(a[end--]);
		
		vector<ll> out(n);
		temp = n;
		int itr = 0;
		int s1 = 0;
		int s2 = 0;
		while(temp >= 2){
			out[itr++] = out1[s1++];
			out[itr++] = out2[s2++];
			temp -= 2;
		}
		if(temp) out[itr++] = out1[s1++];

		ll out_val = 0;
		for(int i=0 ; i<n ; i++){
			if((i-1>=0) && (i+1<n) && (out[i] < out[i-1]) && (out[i] < out[i+1]))
				out_val++;
		}
		
		reverse(out2.begin(),out2.end());
		vector<ll> out_rev(n);
		temp = n;
		itr = 0;
		s1 = 0;
		s2 = 0;
		while(temp >= 2){
			out_rev[itr++] = out1[s1++];
			out_rev[itr++] = out2[s2++];
			temp -= 2;
		}
		if(temp) out_rev[itr++] = out1[s1++];

		ll out_val2 = 0;
		for(int i=0 ; i<n ; i++){
			if((i-1>=0) && (i+1<n) && (out_rev[i] < out_rev[i-1]) && (out_rev[i] < out_rev[i+1]))
				out_val2++;
		}
		
		if(out_val > out_val2){

			cout << out_val << "\n";
			for(auto e : out) cout << e << " ";
			cout << "\n";

		}
		else{
			cout << out_val2 << "\n";
			for(auto e : out_rev) cout << e << " ";
			cout << "\n";



		}
    }
    return 0;
}

