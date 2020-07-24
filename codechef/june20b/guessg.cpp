#include<iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int start1,start2,end1,end2;
    start1 = 1;
    start2 = 1;
    end1 = N;
    end2 = N;
    int mid1 = (start1 + end1)/2;
    int mid2 = (start2 + end2)/2;
    char char1,char2;
    while(true){
        cout << mid1 << endl;
        cin >> char1;
        cout << mid2 << endl;
        cin >> char2;
        if(char1=='G'){
            start1 = mid1 + 1;
        }
        else if(char1=='L'){
            end1 = mid1 - 1;
        }
        else{
            return 0;
        }
        if(char2=='G'){
            start2 = mid2 + 1;
        }
        else if(char2=='L'){
            end2 = mid2 - 1;
        }
        else{
            return 0;
        }
        mid1 = (start1 + end1)/2;
        mid2 = (start2 + end2)/2;
    }
}
