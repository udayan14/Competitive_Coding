#include<iostream>

using namespace std;

long long int prime = 1000000007;

long long int modexp(long long int x, long long int y){
    if(x==1)
        return 1;
    else if(y==0)
        return 1;
    else{
        long long int temp = modexp(x,y/2);
        long long int out = (temp*temp)%prime;
        return (y&1) ? (out*x)%prime : out;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,a;
        cin >> n >> a;
        long long int p[n+1];
        p[0] = 1;
        long long int temp = a;
        for(int i=1 ; i<=n ; ++i){
            temp = (p[i-1] * temp)%prime;
            p[i] = modexp(temp,2*i-1);
        }
        long long int output = 0;
        for(int i=1 ; i<=n ; i++)
            output = (output + p[i])%prime;
        cout << output << "\n";
    }
}
