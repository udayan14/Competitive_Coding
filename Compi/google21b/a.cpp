#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int cas = 1 ; cas<=t ; cas++){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> out(n,0);
		int curr = 1;
		out[0] = 1;
		for(int i=1 ; i<n ; i++){
			if(s[i] > s[i-1]) curr++;
			else curr = 1;
			out[i] = curr;
		}
		
        cout << "Case #" << cas << ": ";
		for(auto e : out) cout << e << " ";
		cout << "\n";
    }
}
