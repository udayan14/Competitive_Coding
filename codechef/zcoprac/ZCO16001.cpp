#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n],b[n],c[n],d[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    for(int i=0 ; i<n ; i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    // Make copies of sorted arrays.
    copy(a,a+n,c);
    copy(b,b+n,d);

    int temp = k;
    int i = n-1;
    //Assuming array a is the lower half
    while(i>=0 && temp>0 && a[i] > b[n-1-i]){
        swap(a[i],b[n-i-1]);
        i--;
        temp--;
    }
    int max1 = *max_element(a,a+n);
    int max2 = *max_element(b,b+n);
    int ans = max1 + max2;

    //The other way
    temp = k;
    i = n-1;
    while(i>=0 && temp>0 && d[i] > c[n-i-1]){
        swap(d[i],c[n-i-1]);
        i--;
        temp--;
    }

    //Overall answer
    max1 = *max_element(c,c+n);
    max2 = *max_element(d,d+n);
    ans = min(ans,max1+max2);
    cout << ans << "\n";
}
