#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>


using namespace std;

vector<vector<long long int> > dp;
vector<vector<short> > dir;
string s1,s2;


long long int find(int i, int j){
    //cout << i << " " << j << "\n";
    if(dp[i][j]!=-1) return dp[i][j];

    else if(i==s1.length() && j==s2.length()){
        dp[i][j] = 0;
        dir[i][j] = 3;
        return dp[i][j];
    }
    else if(i==s1.length()){
        dp[i][j] = find(i,j+1);
        dir[i][j] = 0;
        return dp[i][j];
    }
    else if(j==s2.length()){
        dp[i][j] = find(i+1,j);
        dir[i][j] = 1;
        return dp[i][j];
    }
    else if(s1[i]==s2[j]){
        dp[i][j] = 1 + find(i+1,j+1);
        dir[i][j] = 2;
        return dp[i][j];
    }
    else{
        long long int dir0 = find(i,j+1);
        long long int dir1 = find(i+1,j);
        if(dir0 > dir1){
            dp[i][j] = dir0;
            dir[i][j] = 0;
        }
        else{
            dp[i][j] = dir1;
            dir[i][j] = 1;
        }
        return dp[i][j];
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        cin >> s1 >> s2;
        int n1 = s1.length();
        int n2 = s2.length();
        //cout << "Read\t";
        dp = vector<vector<long long int>> (n1+1,vector<long long int> (n2+1,-1));
        dir = vector<vector<short>> (n1+1,vector<short> (n2+1,0));
        //cout << "done init\n"; 
        find(0,0);
        //cout << "done find\n";
        int i=0;
        int j=0;

        /*for(auto v : dp){*/
            //for(auto e : v){
                //cout << e << "\t";
            //}
            //cout << "\n";
        //}
        //cout << "\n";
        //for(auto v : dir){
            //for(auto e : v){
                //cout << e << "\t";
            //}
            //cout << "\n";
        //}


        vector<char> out;
        while(i<n1 && j<n2){
            switch(dir[i][j]){
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    out.push_back(s1[i]);
                    i++;
                    j++;
                    break;
            }
        }
        for(auto c : out) cout << c;
        cout << "\n";
    }
    return 0;
}

