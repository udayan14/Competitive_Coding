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
    cin >> t;

    while(t--){
        int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> blocks;
		int fst_blk = 0;
		int last_blk = 0;
		int init_score = 0;
		
		bool prev = false;
		for(int i=0 ; i<n ; i++){
			if(s[i]=='W'){
				if(prev) init_score += 2;
				else{
					prev = true;
					init_score += 1;
				}
			}
			else{
				prev = false;
			}
		}
		int start_ind = 0;
		while(start_ind < n && s[start_ind]=='L'){
			start_ind++;
		}
		if(k==0){
			cout << init_score << "\n";
			continue;
		}

		if(start_ind==n){
			int out = 1 + 2 * (k-1);
			cout << out << "\n";
			continue;
		}
		
		fst_blk = start_ind;

		int end_index = n-1;
		while(end_index >= 0 && s[end_index]=='L'){
			end_index--;
		}

		last_blk = n - 1 - end_index;
		
		int count = 0;
		for(int i= start_ind ; i<= end_index ; i++){
			if(s[i]=='L') count++;
			else{
				if(count > 0){
					blocks.push_back(count);
					count = 0;
				}
			}
		}
		sort(blocks.begin(),blocks.end());
		for(int i= 0 ; i<blocks.size() ; i++){
			if(blocks[i] <= k){
				k -= blocks[i];
				init_score += 2*blocks[i] + 1;
			}
			else{
				init_score += 2*k;
				k = 0;
				break;
			}
		}
		if(k==0){
			cout << init_score << "\n";
			continue;
		}
		if(fst_blk > last_blk) swap(fst_blk,last_blk);
		if(fst_blk <= k){
			k -= fst_blk;
			init_score += 2*fst_blk;
			init_score += 2*min(k,last_blk);
			k = 0;
		}
		else{
			init_score += 2*k;
			k = 0;
		}
		cout << init_score << "\n";
		continue;
    }
    return 0;
}

