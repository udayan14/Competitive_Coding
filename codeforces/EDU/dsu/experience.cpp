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
	void init(int n){
		parent = vector<int> (n+1);
		rank = vector<int> (n+1,0);
		for(int i=0 ; i<=n ; i++) parent[i] = i;
	}

	int get(int a){
		if(a == parent[a]) return a;
		parent[a] = get(parent[a]);
		return parent[a];
	}


	void unite(int a, int b){
		a = get(a);
		b = get(b);
		if(rank[a] == rank[b]) rank[a]++;

		if(rank[a] > rank[b]) parent[b] = a;
		else parent[a] = b;
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
				int u, v;
				cin >> u >> v;
				if(st.get(u)==st.get(v))
					cout << "YES\n";
				else cout << "NO\n";
			}
		}
    }
    return 0;
}

