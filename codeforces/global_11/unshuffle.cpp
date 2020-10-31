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
		vector<int> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		vector<vector<int>> out;
		int fst = 0;
		int lst = 0;
		for(int i=0 ; i<n ; i++){
			vector<int> out_vec;
			for(int j=0 ; j< fst ; j++) out_vec.push_back(1);
			int k=fst;
			for(;k<n-lst ; k++){
				if(i&1){
					if(a[k]==lst+1) break;
				}
				else if(a[k]==n-lst) break;
			}
			if(k-fst) out_vec.push_back(k-fst);
			if(n-lst-k) out_vec.push_back(n - lst - k);
			for(int j=0 ; j<lst ; j++) out_vec.push_back(1);
			if(out_vec.size()>1) out.push_back(out_vec);
			
			vector<int> temp(n);
			int count = 0;
			for(int j=n-1 ; j>=n-lst ; j--) temp[count++] = a[j];
			for(int j=k ; j<n-lst ; j++) temp[count++] = a[j];
			for(int j=fst ; j<k ; j++) temp[count++] = a[j];
			for(int j=fst-1 ; j>=0 ; j--) temp[count++] = a[j];
			//cout << "Array a is : ";
			//for(auto e : temp) cout << e << ' ';
			//cout << "\n";
			a = temp;
			swap(fst,lst);
			fst++;
			
			bool exit = true;
			for(int i=0 ; i<n && exit ; i++){
				if(a[i]==i+1) continue;
				else exit = false;
			}
			if(exit) break;
		}

		cout << out.size() << "\n";
		for(auto vec : out){
			cout << vec.size() << " ";
			for(auto v : vec){
				cout << v << " ";
			}
			cout << "\n";
		}
    }
    return 0;
}

