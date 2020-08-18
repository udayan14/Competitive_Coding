#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        char c;
        for(int i=0 ; i<n ; i++){
            cin >> c;
            a[i] = (int)(c-'0');
            a[i]--;
        }
        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i=0 ; i<n ; i++){
            sum[i+1] = sum[i] + a[i];
        }
        map<int,int> count;
        for(int i=0 ; i<n+1 ; i++)
            count[sum[i]]++;

        long long int output = 0;
        for(const auto &kvpair : count){
            long long int temp = kvpair.second;
            if(temp > 1) output += (temp*(temp-1))/2;
        }
        cout << output << "\n";
    }
    return 0;
}

