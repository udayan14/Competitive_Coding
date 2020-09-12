//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long int find_first(long long int target, long long int first, long long int last){
        long long int mid,val;
        while(first < last){
            mid = (first + last)/2;
            val = (mid*(mid+1))/2;
            if(val < target){
                first = mid+1;
            }
            else{
                last = mid;
            }
        }
        return first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << find_first(2,1,100) << "\n";
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        if(n%4==1 || n%4==2){
            cout << "0\n";
            continue;
        }
        long long int target = (n*(n+1))/4;
        long long int m_first = find_first(target-n+1,1,n);
        long long int m_last = find_first(target+1,1,n);
        long long int output = 0;
        for(long long int m = m_first ; m<m_last ; m++){
            long long int delta = target - (m*(m+1))/2;
            //cout << "Found " << m << " " << delta << "\n";
            if(delta==0){
                long long int temp = (m*(m-1))/2 + ((n-m)*(n-m-1))/2;
                //cout << "Adding " << temp << "\n";
                output += temp;
            }
            else{
                long long int temp = min(delta,n-m) - max((long long int)0,delta-m);
                //cout << "Adding " << temp << "\n";
                output += temp;
            }
        }
        cout << output << "\n";
    }
    return 0;
}

