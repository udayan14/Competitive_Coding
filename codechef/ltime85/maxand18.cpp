#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        long long int counter[32];
        memset(counter,0,sizeof(counter));
        long long int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            for(int i=0 ; i<32 ; i++){
                if(in&(1<<i))
                    counter[i]++;
            }
        }
        for(int i=0 ; i<32 ; i++)
            counter[i] = counter[i] * (1<<i);
        unsigned long long int output = 0;
        while(k--){
            long long int curr_max = -1;
            int curr_index = -1;
            for(int i=0 ; i<32 ; i++){
                if(counter[i] > curr_max){
                    curr_max = counter[i];
                    curr_index = i;
                }
            }
            counter[curr_index] = -1;
            output |= (1<<curr_index);
        }
        cout << output << "\n";
    }
}
