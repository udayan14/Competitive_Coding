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

void suffix_array(string s, vector<int> &sa, vector<int> &lcp){
    s+='#';
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


int main(){
    string s;
    string t;
    cin >> s >> t;
    long long int n = s.length();
    string temp = s + "$" + t;
    vector<int> output;
    vector<int> lcp;
    suffix_array(temp,output,lcp);
    long long int out = 0;
    int ind = -1;
    for(int i=1 ; i<lcp.size() ; i++){
        if((output[i]>n && output[i-1] < n) || (output[i]<n && output[i-1]>n)){
            if(lcp[i] > out){
                out = lcp[i];
                ind = output[i];
            }
        }
    }
    cout << temp.substr(ind,out) << "\n";
    /*for(auto num : output)*/
        //cout << num << " ";
    //cout << "\n";
    //for(int i=1 ; i<lcp.size() ; i++)
        //cout << lcp[i] << " ";
    /*cout << "\n";*/

}
