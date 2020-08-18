#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*vector<long long int> value;*/
//vector<long long int> weight;
//vector<vector<long long int>> dp;

/*long long int find(long long int n, long long int k){*/
    //if(dp[n][k]!=-1) return dp[n][k];
    //if(n==0){
        //if(weight[n] <= k){
            //dp[n][k] = value[n];
        //}
        //else{
            //dp[n][k] = 0;
        //}
    //}
    //else{
        //if(weight[n] <= k){
            //dp[n][k] = max(find(n-1,k), value[n] + find(n-1,k-weight[n]));
        //}
        //else{
            //dp[n][k] = find(n-1,k);
        //}
    //}

    //return dp[n][k];
//}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n, color_count, k;
        cin >> n >> color_count >> k;

        vector<long long int> a(n);
        vector<long long int> b(n);
        vector<long long int> c(n);
        vector<long long int> w(color_count+1);
        long long int output = 0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        for(int i=1 ; i<=color_count ; i++){
            cin >> w[i];
        }
        map<long long int, map<long long int, long long int>> count;
        map<long long int, map<long long int, long long int>> value_map;
        for(int i=0 ; i<n ; i++){
            count[c[i]][a[i]]++;
        }
       /* cout << "---\n";*/
        //for(auto &kvpair : count){
            //auto color = kvpair.first;
            //for(auto &kvpair2 : kvpair.second){
                //auto slope = kvpair2.first;
                //auto num = kvpair2.second;
                //cout << color << " " << slope << " " << num << "\n";
            //}
        //}
        /*cout << "---\n";*/
        for(const auto &kvpair : count){
            auto color = kvpair.first;
            auto m = kvpair.second;
            vector<pair<long long int, long long int>> temp(m.size());
            int i=0;
            for(const auto &kvpair2 : m){
                temp[i++] = {kvpair2.second,kvpair2.first};
            }
            sort(temp.begin(),temp.end());
            long long int sum = 0;
            long long int sum_sq = 0;
            long long int sum_cb = 0;
            for(auto v : temp){
                sum += v.first;
                sum_sq += v.first * v.first;
                sum_cb += v.first * v.first * v.first;

            }
            
            long long int e2 = (sum*sum - sum_sq)/2;
            output += (e2*sum - sum*sum_sq + sum_cb)/3;

            //cout << "color : " << color <<"\tsum : " << sum << "\n";
            for(auto v : temp){
                sum -= v.first;
                sum_sq -= v.first * v.first;
                long long int temp_val = (sum * sum - sum_sq)/2;
                value_map[color][v.second] = temp_val;
            }
        }
        
        //weight = vector<long long int> (n);
        //value = vector<long long int> (n);
        vector<long long int> dp(k+1);
        for(int i=0 ; i<n ; i++){
            long long int weight = w[c[i]];
            long long int value = value_map[c[i]][a[i]];
            for(int curr_weight = k -weight ; curr_weight >= 0 ; curr_weight--){
                long long int temp = dp[curr_weight] + value;
                if(temp > dp[curr_weight + weight])
                    dp[curr_weight + weight] = temp;
            }
        }
        long long int answer = 0;
        for(int i=0 ; i<=k ; i++){
            if(dp[i] > answer) answer = dp[i];
        }
       /* cout << output << "\n";*/
        //for(auto w: weight) cout << w << " ";
        //cout << "\n";
        //for(auto v: value) cout << v << " ";
        //cout << "\n";

        cout << output - answer << "\n";
    }
    return 0;
}

