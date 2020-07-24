#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        int a[n];
        vector<long long int> indices;
        for(int i=0 ; i<n ; ++i){
            int in;
            cin >> in;
            in = abs(in);
            a[i] = in;
            if(in%2==0)
                indices.push_back(i);
        }
        long long int output = n * (n+1) / 2;
        int len = indices.size();
        if(len>1){
            for(int i=1 ; i<len-1 ; ++i){
                if(a[indices[i]]%4==2)
                    output -= (indices[i] - indices[i-1])*(indices[i+1]-indices[i]);
            }
            if(a[indices[0]]%4==2)
                output -= (indices[0]+1) * (indices[1]-indices[0]);
            if(a[indices[len-1]]%4==2)
                output -= (indices[len-1] - indices[len-2]) * (n - indices[len-1]);
        }
        else if(len == 1){
            if(a[indices[0]]%4==2)
                output -= (indices[0] + 1) * (n - indices[0]);
        }
        cout << output << "\n";
    }

}
