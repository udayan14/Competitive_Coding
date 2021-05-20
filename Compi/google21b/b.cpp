#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void print_vec(vector<int> v){
	for(auto e : v) cout << e << " ";
	cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int cas = 1 ; cas<=t ; cas++){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		int out = 0;

		vector<int> dp_fwd(n,1);
		vector<int> delta_fwd(n,0);

		vector<int> dp_bwd(n,1);
		vector<int> delta_bwd(n,0);

		for(int i=n-2 ; i>=0 ; i--){
			if(a[i+1]-a[i] == delta_fwd[i+1]){
				dp_fwd[i] = dp_fwd[i+1] + 1;
				delta_fwd[i] = delta_fwd[i+1];
			}
			else{
				dp_fwd[i] = 2;
				delta_fwd[i] = a[i+1] - a[i];
			}

			out = max(out,dp_fwd[i]+1);
		}

		for(int i= 1 ; i<n ; i++){
			if(a[i] - a[i-1] == delta_bwd[i-1]){
				dp_bwd[i] = dp_bwd[i-1] + 1;
				delta_bwd[i] = delta_bwd[i-1];
			}
			else{
				dp_bwd[i] = 2;
				delta_bwd[i] = a[i] - a[i-1];
			}
		}

		for(int i=1 ; i<n-1 ; i++){
			if((delta_bwd[i-1] == delta_fwd[i+1]) && ((a[i+1]-a[i-1])==(2*delta_bwd[i-1]))){
				out = max(out,dp_bwd[i-1] + 1 + dp_fwd[i+1]);
			}
		}
		
		if(n>=3){
			if(a[2] - a[0] == 2*delta_fwd[2])
				out = max(out, 2 + dp_fwd[2]);
			if(a[n-1] - a[n-3] == 2 * delta_bwd[n-3])
				out = max(out, 2 + dp_bwd[n-3]);
		}
		out = min(out,n);
		//print_vec(dp_fwd);
		//print_vec(delta_fwd);
		//print_vec(dp_bwd);
		//print_vec(delta_bwd);
        cout << "Case #" << cas << ": " << out << "\n";
    }
}
