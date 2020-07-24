#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int getmex(int a[], int n){
    for(int i=0 ; i<n ; i++){
        if(a[i]==0)
            return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int mex[n+1];
        memset(mex,0,sizeof(mex));
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            mex[a[i]]++;
        }
        int curr;
        vector<int> output;
        while(true){
            curr = getmex(mex,n+1);
            if(curr==n){
                bool flag = false;
                for(int i=0 ; i<n ; i++){
                    if(a[i]!=i)
                    {
                        output.push_back(i);
                        mex[n]++;
                        mex[a[i]]--;
                        a[i] = n;
                        flag = true;
                        break;
                    }
                }
                if(!flag) break;
            }
            else{
                output.push_back(curr);
                mex[a[curr]]--;
                mex[curr]++;
                a[curr] = curr;
            }
        }
        cout << output.size() << "\n";
        for(auto i : output)
            cout << i+1 << " ";
        cout << "\n";
    }
}
