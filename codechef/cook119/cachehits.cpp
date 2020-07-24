#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,b,m;
        cin >> n >> b >> m;
        int output = 0;
        int curr_block = -1;
        int in;
        while(m--){
            cin >> in;
            int temp = in/b;
            if(temp!=curr_block){
                curr_block = temp;
                output++;
            }
        }
        cout << output << "\n";
    }
}
