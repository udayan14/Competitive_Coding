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

long int run_prod(string s){
    int out = 1;
    for(int i=0 ; i<s.length() ; i++){
        int n = s[i] - '0';
        out *= n;
    }
    return out;
}

long int max_run_prod(int n, int k, string s){
    long int max = 0;
    for(int i = 0; i < n-k+1; i++){
        long int prod = run_prod(s.substr(i,k));
        
        if(prod >= max)
            max = prod;
    }
    return max;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        cout << max_run_prod(n,k,num) << endl;
    }
    return 0;
}
