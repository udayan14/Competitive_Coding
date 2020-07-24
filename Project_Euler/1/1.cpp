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

long long int sumtill(long long int n, int k){
    if(n%k==0)
        return n/k - 1 ;
    else 
        return floor(n/k);
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        long long int l3 = sumtill(n,3);
        long long int l5 = sumtill(n,5);
        long long int l15 = sumtill(n,15);
        long long int out = (3*l3*(l3+1)+5*l5*(l5+1)-15*l15*(l15+1))/2;
        cout<<out<<endl;
    }
    return 0;
}
