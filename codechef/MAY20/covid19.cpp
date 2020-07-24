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
        int prev,curr;
        cin >> prev;
        int curr_size = 1;
        int min_size = 100;
        int max_size = 0;
        for(int i=0 ; i<n-1 ; i++){
            cin >> curr;
            if(curr-prev>2){
                if(curr_size < min_size)
                    min_size = curr_size;
                if(curr_size > max_size)
                    max_size = curr_size;
                curr_size = 1;
            }
            else{
                curr_size++;
            }
            prev = curr;
        }
        if(curr_size < min_size)
            min_size = curr_size;
        if(curr_size > max_size)
            max_size = curr_size;
        cout << min_size << " " << max_size << "\n";
    }
 }
