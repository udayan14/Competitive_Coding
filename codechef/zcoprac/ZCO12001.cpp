#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int nest_depth = 0;
    int nest_index = 0;
    int gap_index = 0;
    int start_index = 0;
    int curr_depth = 0;
    int gap_depth = 0;
    for(int i=1 ; i<=n ; ++i){
        int in;
        cin >> in;

        if(in==1){
            if(curr_depth==0)
                start_index = i;
            curr_depth++;
            if(curr_depth>nest_depth){
                nest_depth = curr_depth;
                nest_index = i;
            }
        }
        else{
            curr_depth--;
            if(curr_depth==0){
                if(i-start_index+1 > gap_depth){
                    gap_depth = i-start_index+1;
                    gap_index = start_index;
                }
            }
        }
    }
    cout << nest_depth << " " << nest_index << " " << gap_depth << " " << gap_index << "\n";
}
