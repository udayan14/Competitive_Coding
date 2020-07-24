#include<iostream>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

void print_arr(int a[], int n){
    for(int i=1 ; i<=n ; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n+1];
        int index[n+1];
        for(int i=1 ; i<n+1 ; ++i){
            cin >> a[i];
            index[a[i]] = i;
        }

        int visited[n+1];
        int m = 0;
        vector<pair<int,pair<int,int> > > output;
        stack<pair<int,int> > stk;
        memset(visited,0,sizeof(visited));

        for(int i=1 ; i<n+1 ; ++i){
            if(m>k) break;
            if(!visited[i]){
                visited[i] = 1;
                int j = a[i];
                while(!visited[j]){
                    stk.push(make_pair(i,j));
                    visited[j] = 1;
                    j = a[j];
                }
            }
            while(stk.size() >= 2){
                pair<int,int> p2 = stk.top();
                stk.pop();
                pair<int,int> p1 = stk.top();
                stk.pop();
                if(p1.first==p2.first){
                    output.push_back(make_pair(p2.first,make_pair(p1.second,p2.second)));
                    m++;
                }
                else{
                    output.push_back(make_pair(p1.first,make_pair(p2.first,p1.second)));
                    output.push_back(make_pair(p2.first,make_pair(p2.second,p1.first)));
                    m+=2;
                }
            }
        }
        if( m>k || !stk.empty())
            cout << -1 << "\n";
        else{
            cout << m << "\n";
            for(const auto p : output){
                int a = p.first;
                int b = p.second.first;
                int c = p.second.second;
                cout << index[a] << " " << index[b] << " " << index[c] << "\n";
                int temp = index[a];
                index[a] = index[b];
                index[b] = index[c];
                index[c] = temp;
            }
        }
    }
}
