#include<iostream>
#include<cstring>

using namespace std;

long long int primes[10000];

int sieveOfEratosthenes(){
    memset(primes,0,sizeof(primes));
    int N = 100000;
    int mask[N];
    memset(mask,1,sizeof(mask));
    mask[0] = 0;
    mask[1] = 0;
    int count = 0;
    for(long long int i=2 ; i<N ; ++i){
        if(mask[i]){
            primes[count++] = i;
            for(long long int j=2 ; i*j < N ; ++j){
                mask[i*j] = 0;
            }
        }
    }
    return count;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int lim = sieveOfEratosthenes();
    //for(int i=0 ; i<lim ; ++i)
        //cout << primes[i] << " ";
    //cout << "\n";
    int t;
    cin >> t;
    while(t--){
        long long int X,K;
        cin >> X >> K;
        long long int temp = X;
        long long int count = 0;
        for(int i=0 ; i<lim ; ++i){
            while(temp%primes[i]==0){
                temp/=primes[i];
                count++;
            }
            if(temp==1)
                break;
        }
        if(temp!=1) count++;

        if(count>=K)
            cout << "1\n";
        else
            cout << "0\n";
    }
}

