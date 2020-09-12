//This code was available online at https://csacademy.com/contest/archive/task/tree_swapping/submissions/
// This code is by a use names sumeet_24. I have only made minor modifications,
//Please do a better job at making questions.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert
#define endl '\n'

ll n,ans;
vector<ll> Tree[maxs];
vector<ll> del;
vector<ll> cost;
vector<ll> col;
string s;

void go(ll s,ll p,ll c){
    cost[s] = 0;
    del[s] = 0;

    if(c)
        del[s]++;
    if(col[s])
        del[s]--;

    for(auto d : Tree[s]){
        if( d != p){
            go(d,s,c^1);
            del[s] += del[d];
            cost[s] += cost[d] + abs(del[d]); 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1 ; i<=n ; i++)
            Tree[i].clear();
        del = vector<ll>(n+1,0);
        cost = vector<ll>(n+1,0);
        col = vector<ll>(n+1,0);
        for(ll i=0;i<n-1;i++){
            ll s,d;
            cin>>s>>d;
            Tree[s].pb(d);
            Tree[d].pb(s);
        }
        cin >> s;
        s = ' ' + s;
        for(ll i=1;i<=n;i++){
            if(s[i] == '1')
                col[i] = 1;
        }

        ans=oo;
        go(1,0,0);
        del[1] == 0 ? ans = min(ans,cost[1]) : 0;
        go(1,0,1);
        del[1] == 0 ? ans = min(ans,cost[1]) : 0;

        if(ans == oo){
            cout << -1 << endl;
        }
        else
            cout << ans << endl;

    }   
    return 0;
}   
