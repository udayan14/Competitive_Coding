#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        int q;
        cin >> q;
        long long int x,y;
        while(q--){
            cin >> x >> y;
            long long int temp = x + y;
            auto ind = lower_bound(a,a+n,temp);
            int dist = distance(a,ind);
            if(dist==n){
                cout << n << "\n";
            }
            else if(a[dist]==temp)
                cout << -1 << "\n";
            else{
                cout << dist << "\n";
            }
        }
    }
}
