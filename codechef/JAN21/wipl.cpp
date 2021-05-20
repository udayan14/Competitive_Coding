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
vector<vector<bool>> dp;
vector<int> h;
int n,k;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;

		h = vector<int> (n);
		ll total_height(0);
		for(int i=0 ; i<n ; i++){
			cin >> h[i];
			total_height += h[i];
		}

		sort(h.begin(),h.end(),greater<int>());
		if(n==1 || total_height < 2*k){
			cout << "-1\n";
			continue;
		}
		if(h[1] >= k){
			cout << "2\n";
			continue;
		}
		if(h[0] >= k){
			int out = 1;
			ll curr_sum = 0;
			for(int i=1 ; i<n && curr_sum < k ; i++){
				curr_sum += h[i];
				out++;
			}
			if(curr_sum < k) cout << "-1\n";
			else cout << out << "\n";
			continue;
		}

		// Lets see if greedy get us anywhere. This gets us a good end-point for our dp
		//

		//for(auto ele : h) cout << ele << " ";
		int val1(k), val2(k);
		int r = 0;
		for(int ele : h){
			if(val1 <= 0 && val2 <= 0) break;
			if(val1 > val2) swap(val1,val2);
			val2 -= ele;
			r++;
		}


		// This part has been referred from this Geeksforgeeks article
		// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
		ll sum(0);
		for(int i=0 ; i<r ; i++) sum += h[i];

		dp = vector<vector<bool>> (r+1, vector<bool>(sum+1));
		//cout << "Initialized dp\n";
		for(int i=0 ; i<=r ; i++){
			dp[i][0] = true;
		}
		for(int i=1 ; i<=sum ; i++)
			dp[0][i] = false;

		for(int i=1 ; i<=r ; i++){
			for(int j=1  ; j<=sum ; j++){
				dp[i][j] = dp[i-1][j];
				if(j >= h[i-1]) dp[i][j] = dp[i][j] | dp[i-1][j-h[i-1]];
			}
		}
		vector<long long int> sum_vec(n+1);
		sum_vec[0] = 0;
		for(int i=1 ; i<=n ; i++) sum_vec[i] = sum_vec[i-1] + h[i-1];
		// Binary search on the optimal value.
		int l = 0;
		while(r-l > 1){
			int m = (r+l) / 2;
			//cout << "Binary Search: " << l << " " << r << " " << m << "\n";
			int smaller_height(-1);
			for(int i=sum_vec[m]/2 ; i>=0 ; i--){
				if(dp[m][i]){
					smaller_height = i;
					break;
				}
			}
			if(smaller_height >= k) r = m;
			else l = m;
		}
		int check(-1);
		for(int i=sum_vec[r]/2 ; i>=0 ; i--){
			if(dp[r][i]){
				check = i;
				break;
			}
		}
		if(check>=k) cout << r << "\n"; // r is a good upper bound for our dp.
		else cout << "-1\n";
    }
    return 0;
}

