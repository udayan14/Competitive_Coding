//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n;
        int s;
        cin >> n >> s;
        
        int length = 0;
        long long int temp = n;
        int digit_sum = 0;
        while(temp){
            length++;
            digit_sum += temp%10;
            temp /= 10;
        }
        if(digit_sum <= s){
            cout << "0\n";
            continue;
        }

        vector<long long int > power_of_ten(length+1);
        power_of_ten[0] = 1;
        for(int i=1 ; i<= length ; i++){
            power_of_ten[i] = power_of_ten[i-1] * 10;
        }
        long long int output = power_of_ten[length] - n;
        int curr_sum = 0;
        for(int i=1 ; i<=length && curr_sum < s; i++){
            long long int temp = n/power_of_ten[length-i];
            curr_sum += temp %10;
            if(curr_sum + 1 <= s){
                output = min(output, temp*power_of_ten[length-i] + power_of_ten[length-i] - n);
            }
        }
        cout << output << "\n";
    }
    return 0;
}

