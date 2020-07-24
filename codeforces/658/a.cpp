#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int count1[1001];
        int count2[1001];
        memset(count1,0,sizeof(count1));
        memset(count2,0,sizeof(count2));
        int in;
        while(n--){
            cin >> in;
            count1[in]++;
        }
        while(m--){
            cin >> in;
            count2[in]++;
        }
        
        bool found = false;
        int output = -1;
        for(int i=1 ; i<1001 ; i++){
            if(count1[i]>0 && count2[i]>0){
                found = true;
                output = i;
                break;
            }
        }
        if(found){
            cout << "YES\n";
            cout << 1 << " " << output << "\n";
        }
        else cout << "NO\n";
    }
}
