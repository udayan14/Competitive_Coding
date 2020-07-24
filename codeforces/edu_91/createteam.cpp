#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n, x;
        cin >> n >> x;
        long long int a[n];
        for(int i=0 ; i<n ; i++)
            cin >> a[i];
        sort(a,a+n,greater<long long int>());
        int output = 0;
        int count = 0;
        for(int i=0 ; i<n ; i++){
            count++;
            if(a[i]*count>=x){
                output++;
                count = 0;
            }
        }
        cout << output << "\n";
    }
}
