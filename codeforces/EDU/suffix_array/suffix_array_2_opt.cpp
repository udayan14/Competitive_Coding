#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

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

vector<int> suffix_array(string s){
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
    return p;
}


int main(){
    string s;
    cin >> s;
    vector<int> output = suffix_array(s);
    for(auto n : output)
        cout << n << " ";
    cout << "\n";
}
