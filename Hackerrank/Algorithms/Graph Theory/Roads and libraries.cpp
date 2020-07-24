#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
int q;
cin >> q;
while(q--){
	long int n,m,c_road,c_lib;
	cin >> n >> m >> c_lib>> c_road;
	vector <int> adj[n];
	for(int i = 0 ; i<m ; i++){
		int x,y;
		cin >> x >> y;
		adj[x-1].push_back(y);
		adj[y-1].push_back(x);
		}

	if(c_lib <= c_road)
		cout << n * c_lib << endl;
	else{
		int visited[n+1];
		memset(visited,0,sizeof(visited));
		int comp = 0;
		for(int i = 1 ; i <= n ; i++){
			if(!visited[i]){
				comp++;
				queue<long int> q;
				q.push(i);
				visited[i] = true;
				while(!q.empty()){
					int k = q.front();
					q.pop();
					vector<int> v = adj[k-1];
					for(int j=0 ; j<v.size() ; j++){
						if(!visited[v[j]]){
							visited[v[j]] = true;
							q.push(v[j]);
						}
					}
				}
			}
		}
		//cout << "Comp: " << comp << "n,m: "<< n<<" " << m <<endl;
		long long int out = n*c_road + comp*(c_lib-c_road) ;
		cout << out << endl;
	}

}

}



