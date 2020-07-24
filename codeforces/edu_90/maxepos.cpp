#include<iostream>
#include<vector>
#include<climits>
using namespace std;

long long int Kadane(vector<long long int> v){
    int n = v.size();
    long long int out = INT_MIN;
    long long int here = 0;
    for(int i=0 ; i<n ; i++){
        here += v[i];
        if(here>out) out = here;
        if(here<0) here = 0;
    }
    return out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> odd;
        vector<long long int> even;
        for(int i=0 ; i<n ; i++){
            long long int in;
            cin >> in;
            if((i%2)==0)
                even.push_back(in);
            else odd.push_back(in);
        }
        long long int out = 0;
        for(auto v : even)
            out+=v;

        vector<long long int> res(n/2);
        for(int i=0 ; i<n/2 ; i++){
            res[i] = odd[i] - even[i];
        }
        long long int out1 = out + Kadane(res);
        long long int out2 = out;
        long long int out3 = out;
        if(n%2){
            vector<long long int> res(n/2);
            for(int i=0 ; i<n/2 ; i++){
                res[i] = odd[i] - even[i+1];
            }
            out2 += Kadane(res);
        }
        else{
            vector<long long int> res(n/2-1);
            for(int i=0 ; i<n/2-1 ; i++){
                res[i] = odd[i] - even[i+1];
            }
            out3 += Kadane(res);
        }
        cout << max(max(out,out1),max(out2,out3)) << "\n";
    }
}

