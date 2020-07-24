#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        int fixed_pts=0;
        int prev = 0;
        int holes = 0;
        for(int i=1 ; i<=n ; i++){
            cin >> a[i];
            if(a[i]==i) {
                fixed_pts++;
                if(prev+1 != i)
                    holes++;
                prev = i;
            }
        }
        if(prev+1!=n+1) holes++;
        //cout << holes << "\n";
        if(fixed_pts==n)
            cout << 0 << "\n";
        else if(fixed_pts==0)
            cout << 1 << "\n";
        else if(holes==1)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}
