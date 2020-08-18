#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n , k , z;
        cin >> n >> k >> z;
        vector<int> a(n);
        vector<long long int> sum_a(n+1,0);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            sum_a[i+1] = sum_a[i] + a[i];
        }
        long long int output = sum_a[k+1];
        for(int i = 0 ; i<=z ; i++){
            int limit = k + 1 - 2*i;
            if(limit + 1 <=n && i>0){
                int temp = sum_a[limit+1];
                if(limit-1 >= 0) 
                    if(output < temp + i*a[limit-1] + (i-1)*a[limit])
                        output = temp + i*a[limit-1] + (i-1) * a[limit];
            }
            if(limit < 0) break;
            int temp = sum_a[limit];
            for(int j = 0 ; j<limit-1 ; j++){
                if(temp + i*(a[j]+a[j+1]) > output)
                    output = temp + i*(a[j] + a[j+1]);
            }
        }
        cout << output << "\n";
    }
    return 0;
}

