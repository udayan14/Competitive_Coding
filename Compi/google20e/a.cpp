#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int cas = 1 ; cas<=t ; cas++){
            int n;
            cin >> n;
            vector<int> a(n);
            for(int i=0 ; i<n ; i++){
                        cin >> a[i];
                    }
            vector<int> diff(n-1);
            for(int i=0 ; i<n-1 ; i++){
                        diff[i] = a[i+1] - a[i];
                    }
            int out = 0;
            int prev = diff[0];
            int curr_count = 1;
            for(int i=1 ; i<n-1 ; i++){
                        if(diff[i]==prev){
                                        curr_count++;
                                    }
                        else{
                                        if(curr_count > out) out = curr_count;
                                        curr_count = 1;
                                        prev = diff[i];
                                    }
                    }
            if(curr_count > out) out = curr_count;
            cout << "Case #" << cas << ": " << out+1 << "\n";
        }
}
