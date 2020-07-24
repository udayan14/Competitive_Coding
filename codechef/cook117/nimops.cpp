#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s,r;
        vector<int> gap;
        cin >> s >> r;
        int n = s.length();
        int start = 0;
        int end = n;
        while(s[start]==r[start] && start < end)
            start++;
        if(start==end){
            cout << 0 << "\n";
            continue;
        }
        while(s[end-1]==r[end-1])
            end--;
        int curr_val = 0;
        for(int i=start ; i<end ; ++i){
            if(s[i]==r[i])
                curr_val++;
            else if(s[i]!=r[i] && curr_val!=0){
                gap.push_back(curr_val);
                curr_val = 0;
            }
        }
        long long int count = end - start;
        long long int cost = count;
        long long int k = 1;
        sort(gap.begin(),gap.end(),greater<int>());
        for(auto val : gap){
            k++;
            count -= val;
            long long int temp = count*k;
            if(temp < cost)
                cost = temp;
        }
        cout << cost << "\n";
    }
}
