#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int number_of_divisors(long n){
    long i = 2;
    int ans = 1;
    int count = 0;
    while(n%2==0){
        n = n/2;
        count++;
    }
    ans*=(1+count);
    if(n==1) return ans;
    for(int i=3; i<=n ; i=i+2){
        int count = 0;
        while(n%i==0){
            n = n/i;
            count++;
        }
        ans *= (1+count);
    }
    return ans;
}

void Initialize(int n, vector <int> &a, vector <long int> &b){
    for(int i=1 ; i<=n ; i++){
        long int x = i*(i+1)/2;
        a.push_back(number_of_divisors(x));
        b.push_back(x);
    }
}

int main() {
    vector <int> a;
    vector <long int> b;
    Initialize(50000,a,b);
    int t;
    cin >> t;
    for(int i=0 ; i<t ;i++){
        int n;
        cin >> n;
       // cout<<number_of_divisors(n)<<endl;
        for(int i=1 ; i<a.size() ; i++){
            if(a[i] > n){
                cout<<b[i]<<endl;
                break;
            }
        }
        
    }
    return 0;
}
