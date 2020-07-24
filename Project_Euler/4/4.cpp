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

bool isPalindrome(int n){
    string s = to_string(n);
    string s1 = s.substr(0,3);
    string s2 = s.substr(3,3);
    reverse(s1.begin(),s1.end());
    return (s1 == s2);
}

int bruteForce(int n){
    int max = 101101;
    for(int i = 999 ; i >= 100 ; i--){
        for(int j = i - 1; j >= 100 ; j--){
            if((i%11!=0)&&(j%11!=0))
                continue;
            else{
            int k = i*j;
            if((k<n)&&(isPalindrome(k))&&(k>max))
                max = k;
            }
               
        
    }
}
               return max;
               }



/*
int palindromeJustLessThan(int n){
    int j = n/1000;
    string s = to_string(j);  
    string s1 = to_string(j);
    reverse(s1.begin(),s1.end());
    
    s = s + s1;
    
    int out = stoi(s);
    
    if(out<n) return out;
    else{
        return bruteForce(n);
    }
}
*/

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<< bruteForce(n)<<endl;
    }
    return 0;
}
