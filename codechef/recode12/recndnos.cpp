#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int count[1001];
        int a[n];
        memset(count,0,sizeof(count));
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<n ; i++){
            count[a[i]]++;
            if(i+1 < n && a[i+1]==a[i])
                i++;
        }
        int* ptr = max_element(count,count+1001);
        int out = distance(count,ptr);
        cout << out << "\n";
    }
}
