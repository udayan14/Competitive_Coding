#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0 ; i<n ; ++i)
        cin >> a[i];
    sort(a,a+n);
    long long int output = 0;
    for(int i=0 ; i<n ; i++){
        int* pos = lower_bound(a,a+n,k-a[i]);
        if(pos > a+i)
            output +=  distance(a+i,pos) - 1;
    }
    cout << output << "\n";
}
