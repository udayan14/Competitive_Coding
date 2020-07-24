#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*Took some help from geeks for geeks for modular exponentiation*/
/*I knew the recursive*/
long long int modexp(long long int x, long long int y, long long int p)
{
    long long int out = 1;
    x = x % p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            out = ((out%p)*(x%p)) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = ((x%p)*(x%p)) % p;  
    }
    return out;
}


long long int hyperexp(long long int a, long long int b, long long int m){
    long long out = 1;
    long long out1 = 0;
    long long out2 = 0;
    long long out3 = 0;

    for(long long int i = b; i > 0 ;i--){
        out3 = out2;
        out2 = out1;
        out1 = out;
        out = modexp(a,out,m);
        if(out == out1 && out1 == out2 && out2 == out3)
            return out;
    }
    return out;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0<t ; a0++){
        long long int a, b, m;
        cin >> a >> b >> m;
        cout <<hyperexp(a,b,m)<<endl;
    }
    return 0;
}
