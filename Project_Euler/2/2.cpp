#include <iostream>

using namespace std;

long long int fibsum(long int n){
    
        long long int a = 1;
        long long int b =0;
        long long int c = 1;
        long long int sum = 0;
        long long int check = 1;  //This is (b+c)
        for(long i=1; check <= n ; i++){
            a = b;
            b = c;
            c = a + b;
            check = b+c;
            if(c%2==0)
                sum+=c;                         
        }
        return sum;
    }

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << fibsum(n)<<endl;
    }
    return 0;
}
