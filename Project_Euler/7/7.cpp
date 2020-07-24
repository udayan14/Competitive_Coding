#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int prime(int n, vector <int> &primes){
    int len = primes.size();
    if(n<=len){
        return primes[n-1];
    }
    else{
        for(int i = primes[len-1] + 2 ; ;i=i+2){
            int isprime=1;
            for(int j = 0 ; j < len ; j++){
                if(i%primes[j]==0){
                    isprime = 0;
                    break;
                }
                
                }
            if(isprime==1){
                    primes.push_back(i);
                    return prime(n,primes);
            }
            
        }
    }
}

int main(){
    vector <int> primes;
    primes.push_back(2);
    primes.push_back(3);
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << prime(n,primes) << endl;
        
    }
    return 0;
}
