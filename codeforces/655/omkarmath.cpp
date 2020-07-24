#include<iostream>

using namespace std;

int gcd(int m, int n){
    if(m==0) return n;
    return gcd(n%m,m);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        if(n%2==0){
            cout << n/2 << " " << n/2 << "\n";
            continue;
        }
        bool flag = false;
        int curr_max = -1;
        int curr_ind = -1;
        for(int i=3 ; i*i<=n ; i+=2){
            if(n%i==0){
                flag = true;
                curr_ind = n/i;
                break;
            }
        }
        if(flag){
            cout << curr_ind << " " << n-curr_ind << "\n";
            continue;
        }
        cout << 1 << " " << n-1 << "\n";
    }
}
