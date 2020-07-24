#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

const int NMAX = 10000000;

int next_open[NMAX+1];
int next_matching[NMAX+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int n = s.length();
        for(int i=0 ; i<n+1 ; i++) next_matching[i] = -1; 
        int curr_sum = 0;
        stack<int> stk;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                stk.push(i+1);
                continue;
            }
            else{
                if(stk.empty()) continue;
                int curr = stk.top();
                stk.pop();
                next_matching[curr] = i+1;
            }
        }
        int curr = -1;
        for(int i=n ; i>0 ; i--){
            if(s[i-1]=='(')
                curr = i;
            next_open[i] = curr;
        }
        int q;
        cin >> q;
        int in;
        while(q--){
            cin >> in;
            if(next_open[in]==-1){
                cout << "-1\n";
                continue;
            }
            int index = next_open[in];
            int output = next_matching[index];
            cout << output << "\n";
        }
    }
}

