#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

void count_sort(vector<int> &p, const vector<int> &c){
    int n = p.size();
    vector<int> count(n,0);
    for(auto e : c) count[e]++;

    vector<int> pos(n);
    pos[0] = 0;
    for(int i=1 ; i<n ; i++){
        pos[i] = pos[i-1] + count[i-1];
    }
    vector<int> p_new(n);
    for(auto e : p){
        p_new[pos[c[e]]++] = e;
    }
    p = p_new;
}

void suffix_array(string s, vector<int> &sa, vector<int> &lcp){
    s+='$';
    int n = s.length();
    vector<int> c(n);
    vector<int> p(n);
    {
    //k=0
    vector< pair<char,int> > a(n);
    for(int i=0 ; i<n ; i++) a[i] = {s[i],i};
    sort(a.begin(),a.end());
    for(int i=0 ; i<n ; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i=1 ; i<n ; i++){
        if(a[i].first==a[i-1].first)
            c[p[i]] = c[p[i-1]];
        else
            c[p[i]] = c[p[i-1]] + 1;
    }

    }
    int k=0;
    while((1<<k)<n){
        for(int i=0 ; i<n ; i++){
            p[i] = (p[i] - (1<<k) + n) %n;
        }
        count_sort(p,c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i=1 ; i<n ; i++){
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1] + (1<<k))%n]};
            pair<int,int> curr = {c[p[i]],c[(p[i] + (1<<k))%n]};
            if(prev==curr)
                c_new[p[i]] = c_new[p[i-1]];
            else
                c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }
    sa = p;
    lcp = vector<int> (n);
    k = 0;
    for(int i=0 ; i<n-1 ; i++){
        int pi = c[i]; //index to vec p;
        int j = p[pi-1];
        while(s[i+k]==s[j+k]) k++;
        lcp[pi] = k;
        k = max(0,k-1);
    }
}

inline long long int nc2(long long int n){
    return (n*(n-1))/2;
}

int main(){
    string str;
    cin >> str;
    long long int n = str.length();
    vector<int> output;
    vector<int> lcp;
    suffix_array(str,output,lcp);
    long long int out = (n*(n+1))/2;
    stack<pair<long long int,long long int>> s;
    lcp.push_back(0);
    for(long long int i=1 ; i<lcp.size() ; i++){
        if(s.empty()){
            s.push({i,lcp[i]});
            continue;
        }
        
        auto pair_t = s.top();
        auto curr = pair_t.first;
        if(pair_t.second < lcp[i]){
            s.push({i,lcp[i]});
            continue;
        }
        while(pair_t.second > lcp[i]){
            s.pop();
            auto old_pair_t = s.top();
            long long int old_curr = old_pair_t.second;
            if(old_pair_t.second < lcp[i]){
                out += (pair_t.second - lcp[i]) * nc2(i-curr+1);
                s.push({curr,lcp[i]});
            }
            else{
                out += (pair_t.second-old_pair_t.second) * nc2(i-curr+1);
            }
            pair_t = s.top();
            curr = pair_t.first;
        }
    }
    cout << out << "\n";
}
