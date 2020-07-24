#include<iostream>
#include<vector>
#include<array>
#include<deque>

using namespace std;

long long int p = 1000000007;
int n,q;
array<array<long long int,21>, 21> dp;
deque<string> city;

void compute(){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i==j) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    for(int c=1 ; c<city.size() ; c++){
        string s1 = city[c-1];
        string s2 = city[c];
        array<array<long long int,21>, 21> temp;
        temp.fill({});
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=n ; ++j){
                if(j-1>=1 && s2[j-1]==s1[j-2])
                    temp[i][j] = (temp[i][j] + dp[i][j-1]) % p;
                if(s2[j-1]==s1[j-1])
                    temp[i][j] = (temp[i][j] + dp[i][j]) % p;
                if(j+1<=n && s2[j-1]==s1[j])
                    temp[i][j] = (temp[i][j] + dp[i][j+1]) % p;
            }
        }
        dp = temp;
    }
}

void print(){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    string s;
    while(q--){
        cin >> s;
        if(s=="add"){
            string l;
            cin >> l;
            city.push_back(l);
            int len = city.size();
            if(len==1){
                for(int i=1 ; i<=n ; ++i){
                    for(int j=1 ; j<=n ; ++j){
                        if(i==j) dp[i][j]=1;
                        else dp[i][j]=0;
                    }
                }
            }
            else{
                string s1 = city[len-2];
                string s2 = city[len-1];
                array<array<long long int,21>, 21> temp;
                temp.fill({});
                for(int i=1 ; i<=n ; ++i){
                    for(int j=1 ; j<=n ; ++j){

                        if(j-1>=1 && s2[j-1]==s1[j-2])
                            temp[i][j] = (temp[i][j] + dp[i][j-1]) % p;
                        if(s2[j-1]==s1[j-1])
                            temp[i][j] = (temp[i][j] + dp[i][j]) % p;
                        if(j+1<=n && s2[j-1]==s1[j])
                            temp[i][j] = (temp[i][j] + dp[i][j+1]) % p;
                    }
                }
                dp = temp;
            }
        }
        else if(s=="remove"){
            city.pop_front();
            compute();
        }
        else{
            int i,j;
            cin >> i >> j;
            cout << dp[i][j] << "\n";
        }
        //print();
    }
}
