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

struct edge{
	int dst, num;
};

//vector<vector<edge>> adj;
vector<vector<edge>> adj_tr;
vector<int> par;
vector<double> dp;
	
double longest_dist(int index, double baseline){
	if(dp[index] <= 1.0e12) return dp[index];

	double curr_min = 1e13;
	for(auto inc : adj_tr[index]){
		auto curr_ind = inc.dst;
		auto weight = inc.num;
		if(curr_min > weight + longest_dist(curr_ind,baseline)){
			curr_min = weight + longest_dist(curr_ind,baseline);
			par[index] = curr_ind;
		}
	}
	dp[index] = curr_min - baseline;
	return dp[index];
}

int main(){
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
		int n, m;
        cin >> n >> m;
		//adj = vector<vector<edge>> (n+1);
		adj_tr = vector<vector<edge>> (n+1);

		int u, v, c;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> c;
			//adj[u].push_back({v,c});
			adj_tr[v].push_back({u,c});
		}
		
		//cout << "Initialized graph\n";
		double l = 0.0;
		double r = 10000001.0;     //inferred from problem constraints
		par = vector<int>(n+1);
		//cout << "Entering loop" << endl;	
		for(int i=0 ; i<100 ; i++){
			//cout << "Loopy\t";
			double mid = (l+r)/2.0;
			dp = vector<double>(n+1,1.0e13);
			dp[1] = 0.0;
			double temp = longest_dist(n,mid);
			if(temp > 0) l = mid;
			else r = mid;
		}
		//cout << r << "\n";
		longest_dist(n,r);
		stack<int> s;
		s.push(n);
		while(s.top()!=1){
			s.push(par[s.top()]);
		}

		cout << (int)s.size() - 1<< "\n";
		while(!s.empty()){
			cout << s.top() << " ";
			s.pop();
		}
    }
    return 0;
}

