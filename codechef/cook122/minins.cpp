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
        int n;
		cin >> n;

		vector<ll> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];

		vector<int> visited(n,0);
		vector<int> blocks;
		int curr_len = 0;
		for(int i=0 ; i<n ; i++){
			if(visited[i]==0){
				stack<int> s;
				s.push(i);
				visited[i] = 1;
				curr_len = 0;
				while(!s.empty()){
					int curr = s.top();
					s.pop();
					curr_len++;
					int next = curr + 1;
					if(next >= n) next -= n;
					if(visited[next]==0 && __gcd(a[curr],a[next])!=1){
						s.push(next);
						visited[next] = 1;
					}
					int prev = curr - 1;
					if(prev < 0) prev += n;
					if(visited[prev]==0 && __gcd(a[curr],a[prev])!=1){
						s.push(prev);
						visited[prev] = 1;
					}
				}
				if(curr_len > 1) blocks.push_back(curr_len);
			}
		}
		for(auto e : blocks) cout << e << " ";
		cout << "\n";
		vector<int> out(n+1,0);
		ll temp;
		for(auto ele : blocks){
			for(int k=2 ; k<=n ; k++){
				
				if(k > ele) break;

				if(ele==n){ 
					if((ele-1)%(k-1)==0)
						out[k] += (ele-1)/(k-1);
					else
						out[k] += (ele-1)/(k-1) + 1;
				}
				else{

					out[k] += (ele-1)/(k-1);
				}
				//if((ele-1)%(k-1)==0)
					//temp = (ele-1)/(k-1);
				//else
					//temp = (ele-1)/(k-1) + 1;
				//out[k] += temp;
				if(temp==0) break;
			}
		}
		for(int i=2 ; i<=n ; i++) cout << out[i] << " ";
		cout << "\n";
    }
    return 0;
}

