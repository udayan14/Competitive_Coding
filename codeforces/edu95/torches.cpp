#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long int x, y, k;
        cin >> x >> y >> k;
        long long int goal = (y+1) * k;
        long long int tries;
        if((goal-1) % (x-1) == 0 ) tries = (goal-1) / (x-1);
        else tries = (goal-1) / (x-1) + 1;

        cout << tries + k << "\n";
    }
}
