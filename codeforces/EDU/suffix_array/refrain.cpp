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

void suffix_array(vector<int> s, vector<int> &sa, vector<int> &lcp){
    s.push_back(0);
    int n = s.size();
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
        while((i+k<n) && (j+k<n) && (s[i+k]==s[j+k])) k++;
        lcp[pi] = k;
        k = max(0,k-1);
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    if(n==1){
        cout << 1 << "\n";
        cout << 1 << "\n";
        cout << a[0] << "\n";
        return 0;
    }
    vector<int> output;
    vector<int> lcp;
    suffix_array(a,output,lcp);
   /* for(auto num : output)*/
        //cout << num << " ";
    //cout << "\n";
    //for(int i=1 ; i<lcp.size() ; i++)
        //cout << lcp[i] << " ";
    /*cout << "\n";*/
    stack<long long int> s;
    int size = lcp.size();
    vector<long long int> fwd(size,size);
    for(int i=0 ; i<size ; i++){
        if(s.empty() || lcp[s.top()] < lcp[i]){
            s.push(i);
            continue;
        }
        while(!s.empty() && lcp[s.top()] > lcp[i]){
            fwd[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();

    vector<long long int> bwd(size,-1);
    for(int i=size-1 ; i>=0 ; i--){
        if(s.empty() || lcp[s.top()] < lcp[i]){
            s.push(i);
            continue;
        }
        while(!s.empty() && lcp[s.top()] > lcp[i]){
            bwd[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();

    long long int out = n;
    long long int out_ind = 0;
    long long int out_len = n;
    bool found = false;
    for(int i=0 ; i<size ; i++){
        long long int temp = lcp[i] * (fwd[i] - bwd[i]);
        if(temp > out){
            out = temp;
            out_len = lcp[i];
            out_ind = i;
            found = true;
        }
    }
    cout << out << "\n";
    cout << out_len << "\n";
    for(int i=0 ; i<out_len ; i++){
        if(found) cout << a[output[out_ind] + i] << " ";
        else cout << a[i] << " ";
    }
    cout << "\n";

}
