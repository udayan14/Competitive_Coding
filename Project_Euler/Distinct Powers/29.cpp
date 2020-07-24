#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool checked[n+1];
    memset(checked,false,sizeof(checked));
    long int out = 0;
    int mid1 = floorf(cbrt(n));
    int mid2 = floorf(sqrt(n));
    if(mid1==1) mid1=2;
    if(mid2==1) mid1=2;
    for(int i=2 ; i<= mid1 ; i++){
        if(checked[i]==false){            
            int x = floorf(log(n)/log(i));
            int y = x*(n-1);
            int v[y];
            int id = 0;
            int temp = i;
            for(int j=1 ; j<=x; j++){
                checked[temp] = true;
                temp*=i;
                for(int k = 2 ; k<=n ; k++){
                    v[id] = k*j;
                    id++;
                }
            }
            sort(v, v+y);
            int prev = 0;
            for(int t=0 ; t<y ; t++){
                if(prev!=v[t])
                    out++;
                prev = v[t];
            }
            
           //cout<<endl;
        }
    }
long int count = 0;
for(int i=mid1+1 ; i<=mid2 ; i++){
    if(checked[i]==false){
        checked[i] = true;
        checked[i*i]=true;
        count++;
    }
}
out+=count*(2*(n-1) - (n-1)/2);

count = 0;
for(int i=mid2+1 ; i<n+1 ; i++){
    if(checked[i]==false){
      checked[i]=true;  
      count++;  
    }
}
out+=count*(n-1);
cout << out <<endl;
// for (int i = 0; i < n+1; ++i)
// {
//     for (int j = 0; j < n+1; ++j)
//     {
//         cout<<arr[i][j].base <<"^" <<arr[i][j].exp<<"   ";
//     }
//     cout<<endl;
// }9981236306
    
}
