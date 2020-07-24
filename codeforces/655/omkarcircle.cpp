#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    if(n==1){
        cout << a[0] << "\n";
    }
    else if(n==3){
        int output = a[0]+a[1];
        output = max(output,a[1]+a[2]);
        output = max(output,a[0]+a[2]);
        cout << output << "\n";
    }
    else{
        int b[2*n];
        for(int i=0 ; i<=n/2 ; i++)
            b[i] = a[2*i];
        for(int i=0 ; i<n/2 ; i++)
            b[i+n/2+1] = a[2*i+1];
        for(int i=0 ; i<n ; i++)
            b[i+n] = b[i];
        long long int output = 0;
        for(int i=0 ; i<=n/2 ; i++)
            output += b[i];
        int start = 0;
        int end = n/2+1;
        long long int temp = output;
        while(end<2*n){
            temp -= b[start];
            temp += b[end];
            start++;
            end++;
            if(temp > output){
                output = temp;
            }
        }
        cout << output << "\n";
    }
}
