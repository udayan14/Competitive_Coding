#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int s,n;
        cin >> s >> n;
        if(n%2)
            n--;
        long long int output = 0;
        if(s%n==0){
            output = s/n;
        }
        else if(s%n==1)
            output = s/n + 1;
        else if(s%2==0)
            output = s/n + 1;
        else
            output = s/n + 2;
        cout << output << "\n";
    }
}
