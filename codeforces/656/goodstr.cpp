#include<iostream>

using namespace std;

int answer(char a[], int start, int end, char c){
    if(start+1==end){
        if(a[start]==c)
            return 0;
        else return 1;
    }
    int mid = (start+end)/2;
    int count1 = 0;
    for(int i=start ; i<mid ; i++){
        if(a[i]!=c)
            count1++;
    }
    int count2 = 0;
    for(int i=mid ; i<end ; i++){
        if(a[i]!=c)
            count2++;
    }
    return min(count1+answer(a,mid,end,c+1),answer(a,start,mid,c+1)+count2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char a[n];
        for(int i=0 ; i<n ; i++)
            cin >> a[i];

        cout << answer(a,0,n,'a') << "\n";
    }
}
