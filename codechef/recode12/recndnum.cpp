#include<iostream>

using namespace std;

long long int p = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n,k;
        cin >> n >> k;
        long long int block_num;
        if(n==0){
            cout << (k*(k-1))%p << "\n";
            continue;
        }
        if(k==1)
            block_num = n;
        else
            block_num = n + (k-2)/2  + 1;
        long long int sum = (block_num * (block_num-1))%p;
        if(k%2==0)
            sum = (sum + n)%p;
        else
            sum = (sum + 2*block_num - n)%p;
        cout << sum << "\n";
    }
}

