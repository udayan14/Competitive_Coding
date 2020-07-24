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

int smallestN(int n, vector <int> primes){
    long out = 1;
    for(int i = 0 ; i < primes.size() ; i++){
        int count = 0;
        while(pow(primes[i],count)<=n){
            count++;
        }
        out *= pow(primes[i],count-1);
    }
    return out;
}

int main(){
    int t;
    cin >> t;
    vector <int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << smallestN(n, primes) << endl;
    }
    return 0;
}
