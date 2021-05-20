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
int n, m, d;

struct edge{
	int dst, num;
};

vector<vector<edge>> adj;
vector<int> path;

bool pathExists(int val){
	pair<int,int> temp = {1,0};
	queue<pair<int,int>> q;
	q.push(temp);
	vector<bool> visited(n+1,false);
	vector<bool> in_queue(n+1,false);
	in_queue[1] = true;
	while(!q.empty()){
		auto curr = q.front();
		visited[curr.first] = true;
		q.pop();
		if(curr.first==n){
			if(curr.second <= d) return true;
			else return false;
		}
		for(auto e : adj[curr.first]){
			if(!visited[e.dst] && !in_queue[e.dst] && e.num <= val){
				q.push({e.dst,curr.second+1});
				in_queue[e.dst] = true;
				visited[e.dst] = true;
			}
		}
	}
	return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        cin >> n >> m >> d;
		adj = vector<vector<edge>> (n+1);

		int u, v, c;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> c;
			adj[u].push_back({v,c});
		}
		

		int l = -1;
		int r = 1e9;

		if(!pathExists(r)){
			cout << -1 << "\n";
			continue;
		}

		while(r-l > 1){
			int m = (l+r)/2;
			if(pathExists(m)){
				r = m;
			}
			else l = m;
		}
		
		int out = 0;
		// Getiing the actual path
		vector<int> parent(n+1,-1);
		pair<int,int> temp = {1,0};
		queue<pair<int,int>> q;
		q.push(temp);
		vector<bool> visited(n+1,false);
		vector<bool> in_queue(n+1,false);
		in_queue[1] = true;
		while(!q.empty()){
			auto curr = q.front();
			q.pop();
			if(curr.first==n){
				break;
			}
			for(auto e : adj[curr.first]){
				if(!visited[e.dst] && !in_queue[e.dst] && e.num <= r){
					q.push({e.dst,curr.second+1});
					in_queue[e.dst] = true;
					parent[e.dst] = curr.first;
				}
			}
		}
		
		stack<int> s;
		s.push(n);
		while(s.top()!=1){
			s.push(parent[s.top()]);
		}

		cout << (int)s.size() - 1<< "\n";
		while(!s.empty()){
			cout << s.top() << " ";
			s.pop();
		}
		// TODO Get the Actual Path.
    }
    return 0;
}

