#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

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
        vector< pair<pair<int,int>,int> > a(n);
        for(int i=0 ; i<n ; i++) a[i] = {{c[i],c[(i + (1<<k))%n]},i};
        sort(a.begin(),a.end());
        for(int i=0 ; i<n ; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1 ; i<n ; i++){
            if(a[i].first==a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] + 1;
        }

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
