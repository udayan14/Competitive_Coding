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

long largestPrimeFactor(long n){
    
    long i = 2;
    long ans = 2;
    while(n%2==0){
        n = n/2;
    }
    if(n==1) return ans;
    else{
        long org;
        for(int i=3; i<=sqrt(n); i=i+2){
            long org = n;
            if(n%i==0){
                while(n%i==0){
                    n = n/i;
                }
                ans = i;
            }
        }
        if(n>ans) return n;
            else return ans;
    }
    
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << largestPrimeFactor(n) << endl;
    }
    return 0;
}
