#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include<algorithm>

using namespace std;

long long int p = 1000000007;
int nmax = 2000000;
vector<long long int> golomb(nmax);
vector<long long int> cumsum(nmax);
vector<long long int> answer(nmax);

long long int getsum(long long int n){
    auto it = upper_bound(cumsum.begin(),cumsum.end(),n);
    long long int ind = distance(cumsum.begin(),it);
    long long int out = answer[ind-1];
    out = (out + (((((n - cumsum[ind-1])%p)*ind)%p)*ind)%p )%p;
    if(out < 0) out+=p;
    return out;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    golomb[1] = 1;
    cumsum[0] = 0;
    cumsum[1] = 1;
    answer[0] = 0;
    answer[1] = 1;
    for(int i=2 ; i<nmax ; i++){
        golomb[i] = 1 + golomb[i - golomb[golomb[i-1]]];
        cumsum[i] = cumsum[i-1] + golomb[i];
        answer[i] = (answer[i-1] + (((i*i)%p)*golomb[i])%p) %p;
    }
 /*   for(int i=nmax-100 ; i<nmax ; i++){*/
        //cout << cumsum[i] << " ";
  /*  }*/
    int t;
    cin >> t;
    while(t--){
        long long int l,r;
        cin >> l >> r;
        
        long long int out1 = getsum(l-1);
        long long int out2 = getsum(r);
        
        long long int ans = (out2 - out1)%p;
        if(ans < 0) ans+=p;
        //cout << out1 << " " << out2 <<"\n";
        //long long int check = 0;
        //for(int i=l ; i<=r ; i++){
            //check = (check + (golomb[i]*golomb[i])%p)%p;
        //}
        //cout << check << "\n";
        cout << ans << "\n";
        //assert (check==ans);
    }
    return 0;
}

