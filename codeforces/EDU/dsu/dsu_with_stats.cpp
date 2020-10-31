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

struct DSU{
	vector<int> parent;
	vector<int> rank;
	vector<int> min_val;
	vector<int> max_val;
	vector<int> sum_val;

	void init(int n){
		parent = vector<int> (n+1);
		rank = vector<int> (n+1,0);
		for(int i=0 ; i<=n ; i++) parent[i] = i;
		min_val = parent;
		max_val = parent;
		sum_val = vector<int> (n+1,1);
	}

	int get(int a){
		if(a == parent[a]) return a;
		parent[a] = get(parent[a]);
		return parent[a];
	}

	array<int,3> get_stat(int a){
		a = get(a);
		return {min_val[a],max_val[a],sum_val[a]};
	}

	void unite(int a, int b){
		a = get(a);
		b = get(b);
		if(a==b) return;
		if(rank[a] == rank[b]) rank[a]++;

		if(rank[a] > rank[b]){
			parent[b] = a;
			sum_val[a] += sum_val[b];
			amin(min_val[a],min_val[b]);
			amax(max_val[a],max_val[b]);
		}
		else{
			parent[a] = b;
			sum_val[b] += sum_val[a];
			amin(min_val[b],min_val[a]);
			amax(max_val[b],max_val[a]);
		}
	}
};

const long long int p = 1000000007;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n,m;
		cin >> n >> m;
		DSU st;
		st.init(n);
		string q;
		while(m--){
			cin >> q;
			if(q=="union"){
				int u,v;
				cin >> u >> v;
				st.unite(u,v);
			}
			else if(q == "get"){
				int u;
				cin >> u;
				auto v = st.get_stat(u);
				cout << v[0] << " " << v[1] << " " << v[2] << "\n";
			}
		}
    }
    return 0;
}

