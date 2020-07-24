#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;

        long long int a[26];
        long long int sum[26];
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));

        for(const auto& chr : s){
            a[chr-'a']++;
        }
        sort(a,a+26);
        sum[0] = a[0];
        for(int i=1 ; i<26 ; i++)
            sum[i] = sum[i-1] + a[i];

        long long int c;
        while(q--){
            cin >> c;
            long long int* ptr = lower_bound(a,a+26,c);
            long long int index = distance(a,ptr);
            long long int output = n;
            if(index-1 >= 0)
                output -= sum[index-1];
            output -= c * (26 - index);
            cout << output << "\n";
        }
    }
}
