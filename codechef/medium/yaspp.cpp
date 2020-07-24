#include<iostream>
#include<queue>
#include<cstring>
#include<unordered_set>
using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector <pair<int,int> > edge[n+1];
	for(int i=0 ; i<m ; i++)
	{
		int u,v,c;
		cin >> u >> v >> c;
		edge[u].push_back(make_pair(v,c));
		edge[v].push_back(make_pair(u,c));
	}
	int s,t;
	cin >> s >> t;
	queue<pair<int,int> > q1;
	queue<pair<int,int> > q2;
	unordered_set<pair<int,int>, pair_hash > visited;
	for(int i=0 ; i<edge[s].size() ; i++)
	{
		q1.push(edge[s][i]);
		visited.insert(make_pair(s,edge[s][i].second));
		//cout << "pushing " << edge[s][i].first << " " << edge[s][i].second << " in queue1\n";
	}
	int cost = 0;
	
	while(!q1.empty() || !q2.empty())
	{
		while(!q1.empty())
		{
			pair<int,int> curr = q1.front();
			q1.pop();
			visited.insert(curr);
			q2.push(curr);
			//cout << "popping " << curr.first << " " << curr.second << " from queue1\n";
			//cout << "pushing " << curr.first << " " << curr.second << " in queue2\n";
			int node = curr.first;
			int color = curr.second;
			if(node==t)
			{
				cout << cost << "\n";
				return 0;
			}
			for(int i=0 ; i<edge[node].size() ; i++)
			{
				if(!visited.count(edge[node][i]) && color==edge[node][i].second)
				{
					q1.push(edge[node][i]);
					//cout << "pushing " << edge[node][i].first << " " << edge[node][i].second << " in queue1\n";
				}
			}
		}
		cost++;
		while(!q2.empty())
		{
			pair<int,int> curr = q2.front();
			q2.pop();
			int node = curr.first;
			int color = curr.second;
			for(int i=0 ; i<edge[node].size() ; i++)
			{
				if(!visited.count(edge[node][i]) && color!=edge[node][i].second)
				{
					q1.push(edge[node][i]);
					visited.insert(make_pair(node,edge[node][i].second));
					//cout << "pushing " << edge[node][i].first << " " << edge[node][i].second << " in queue1\n";
				}
			}
		}
	}
}
