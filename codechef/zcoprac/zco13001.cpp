#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; ++i)
        cin >> a[i];
    sort(a,a+n,greater<int>());
    long long int multipler = n-1;
    long long int output = 0;
    for(int i=0 ; i<n ; ++i){
        output += multipler*a[i];
        multipler-=2;
    }
    cout << output << "\n";
}
