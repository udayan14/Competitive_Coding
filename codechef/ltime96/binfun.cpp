#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

long long int shift(long long int n){
    n |= n>>1;
    n |= n>>2;
    n |= n>>4;
    n |= n>>8;
    n |= n>>16;
    n |= n>>32;
    n++;
    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n);
        vector<long long int> length_as_num(n);
        long long int max_num = -1;
        int max_ind;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            length_as_num[i] = shift(a[i]);
            if(a[i] > max_num){
                max_num = a[i];  
                max_ind = i;
            }
        }
        if(n<500){
            long long int output = -1;
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    long long int temp = a[i]*length_as_num[j] + a[j] - a[j]*length_as_num[i] - a[i];
                    if(temp > output){
                        output = temp;
                    }
                    temp = a[j]*length_as_num[i] + a[i] - a[i]*length_as_num[j] - a[j];
                    if(temp > output)
                        output = temp;

                }
            }
            cout << output << "\n";
            continue;
        }
        long long int output = -1;
        for(int i=0 ; i<n ; i++){
            long long int temp = a[i]*length_as_num[max_ind] + a[max_ind] - a[max_ind]*length_as_num[i] - a[i];
            if(temp > output){
                output = temp;
            }
            temp = a[max_ind]*length_as_num[i] + a[i] - a[i]*length_as_num[max_ind] - a[max_ind];
            if(temp > output)
                output = temp;
        }
        cout << output << "\n";
        
    }
    return 0;
}

