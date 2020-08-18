#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

#define LN 20

using namespace std;

vector<int> sa;
vector<int> lcp;
vector<int> pos;

vector<vector<int>> seg_tree;


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

void suffix_array(string s){
    s+=' ';
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

int get_lcp(int i, int j){
    int pos1 = pos[i];
    int pos2 = pos[j];
    if(pos1 > pos2) swap(pos1,pos2);

    int temp = pos2 - pos1 - 1;
    if(temp==0) return lcp[pos2];
    int index = 0;
    while(temp){
        index++;
        temp/=2;
    }
    index--;
    return min(seg_tree[pos1+1][index],seg_tree[pos2-(1<<index)+1][index]);
}


struct cmp{
    bool operator()(const pair<int,int>p1, const pair<int,int>p2){
        int l1 = p1.first;
        int r1 = p1.second;
        int l2 = p2.first;
        int r2 = p2.second;

        if(l1==l2) return r1<r2;

        int lcp_val = get_lcp(l1,l2);
        if((r1-l1==r2-l2) && (r1-l1+1 <= lcp_val)){
            return p1<p2;
        }
        if(pos[l1]<pos[l2]){
            if(r2-l2+1 <= lcp_val && r1-l1+1 <= lcp_val)
                return r1-l1 < r2-l2;
            if(r2-l2+1 <=lcp_val)
                return false;
            if(r1-l1+1 <= lcp_val)
                return true;
            else
                return true;
        }
        else{
            if(r2-l2+1 <= lcp_val && r1-l1+1 <= lcp_val)
                return r1-l1 < r2-l2;
            if(r2-l2+1 <=lcp_val)
                return false;
            if(r1-l1+1 <= lcp_val)
                return true;
            else
                return false;

        }
    }
};

int main(){
    string s;
    cin >> s;
    suffix_array(s);
    /*for(auto num : sa)*/
        //cout << num << " ";
    //cout << "\n";
    //for(int i=1 ; i<lcp.size() ; i++)
        //cout << lcp[i] << " ";
    /*cout << "\n";*/
    pos = vector<int> (sa.size());
    for(int i=0 ; i<sa.size() ; i++)
        pos[sa[i]] = i;

    seg_tree = vector<vector<int>> (lcp.size(),vector<int>(LN,-1));
    for(int i=0 ; i<LN ; i++){
        for(int j=0 ; j<lcp.size() && j+(1<<i)-1 < lcp.size() ; j++){
            if(i==0){
                seg_tree[j][i] = lcp[j];
            }
            else{
                seg_tree[j][i] = min(seg_tree[j][i-1],seg_tree[j+(1<<(i-1))][i-1]);
            }
        }
    }

/*    for(int i=0 ; i<LN ; i++){*/
        //for(int j=0 ; j<lcp.size() ; j++)
        //{
            //cout << seg_tree[j][i] << " ";
        //}
        //cout << "\n";
    /*}*/
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int l,r;
    for(int i=0 ; i<n ; i++){
        cin >> l >> r;
        v[i] = {l-1,r-1};
        //cout << get_lcp(l,r);
    }
    sort(v.begin(),v.end(),cmp());
    for(auto p: v){
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}
