//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<short> group;
vector<__int128> k_power;
int k;


vector<vector<short>> dp;
vector<short> solve_ans;
vector<short> current_vec;

long long int ans = LLONG_MAX;

short find(int n, long long int sum){
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(sum==0){
        dp[n][sum] = 1;
        return dp[n][sum];
    }
    if(n==0){
        dp[n][sum] = 0;
        return dp[n][sum];
    }
    if(k_power[n] > sum){
        dp[n][sum] = find(n-1,sum);
        return dp[n-1][sum];
    }
    else{
        dp[n][sum] = find(n-1,sum) | find(n-1,sum-k_power[n]);
        return dp[n][sum];
    }
}

void solve(int n, long long int sum){
    if(n==0 || sum == 0) return;
    if(k_power[n] > sum){
        solve(n-1,sum);
    }
    else{
        if(find(n-1,sum-k_power[n])){
            solve_ans[n] = 1;
            solve(n-1,sum-k_power[n]);
        }
        else{
            solve(n-1,sum);
        }
    }
}

void solve_recur(long long int n, __int128 sum1, __int128 sum2){
    if(ans==0) return;
    if(n==0){
        long long int temp = sum1 - sum2;
        if(temp < 0) temp *= -1;
        if(temp < ans){
            ans = temp;
            solve_ans = current_vec;
        }
    }
    else{
        current_vec.push_back(0);
        solve_recur(n-1,sum1+k_power[n],sum2);
        current_vec.pop_back();
        current_vec.push_back(1);
        solve_recur(n-1,sum1,sum2+k_power[n]);
        current_vec.pop_back();
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> k;
    k_power = vector<__int128> (1000001);
    for(long long int i=0 ; i<1000001 ; i++){
        k_power[i] = 1;
        for(int j=0 ; j<k ; j++) k_power[i] *= i;
    }
    if(k==3){
        dp = vector<vector<short>> (21,vector<short>(44101,-1));
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        group = vector<short> (n);
        if(k==1){
            long long int sum1 = 0;
            long long int sum2 = 0;
            for(int i=n ; i>0 ; i--){
                if(sum1 > sum2){
                    sum2 += i;
                    group[i-1] = 1;
                }
                else{
                    sum1 += i;
                }
            }
            ans = sum1 - sum2;
            if(ans < 0) ans *= -1;
            cout << ans << "\n";
            for(auto e : group) cout << e;
            cout << "\n";
        }
        else if(k==2){
            long long int sum1 = 0;
            long long int sum2 = 0;
            for(int i=n ; i>10 ; i--){
                if(sum1 > sum2){
                    sum2 += k_power[i];
                    group[i-1] = 1;
                }
                else{
                    sum1 += k_power[i];
                }
            }
            ans = LLONG_MAX;
            solve_recur(min(10,n),sum1,sum2);
            reverse(solve_ans.begin(),solve_ans.end());
            cout << ans << "\n";
            for(auto e : solve_ans) cout << e;
            for(int i=10 ; i<n ; i++) cout << group[i];
            cout << "\n";
        }
        else if(k==3){
            if(n==1){
                cout << "1\n";
                cout << "0\n";
                continue;
            }
            else if(n==2){
                cout << "7\n";
                cout << "10\n";
                continue;
            }
            else if(n==3){
                cout << "18\n";
                cout << "110\n";
                continue;
            }
            else if(n==4){
                cout << "28\n";
                cout << "1110\n";
                continue;
            }
            else if(n==5){
                cout << "25\n";
                cout << "11110\n";
                continue;
            }
            else if(n==6){
                cout << "7\n";
                cout << "101110\n";
                continue;
            }
            else if(n==7){
                cout << "26\n";
                cout << "0001110\n";
                continue;
            }
            else if(n==8){
                cout << "4\n";
                cout << "00110110\n";
                continue;
            }
            else if(n==9){
                cout << "5\n";
                cout << "011010110\n";
                continue;
            }
            else if(n==10){
                cout << "1\n";
                cout << "0111111010\n";
                continue;
            }
            else if(n==11){
                cout << "12\n";
                cout << "11110010110\n";
                continue;
            }
            else if(n==12){
                cout << "0\n";
                cout << "001011100110\n";
                continue;
            }
            else if(n==13){
                cout << "1\n";
                cout << "1111101111100\n";
                continue;
            }
            else if(n==14){
                cout << "1\n";
                cout << "10100110010110\n";
                continue;
            }
            else if(n==15){
                cout << "0\n";
                cout << "001111010111100\n";
                continue;
            }
            else if(n==16){
                cout << "0\n";
                cout << "0110100110010110\n";
                continue;
            }
            else if(n==17){
                cout << "1\n";
                cout << "00010110111110010\n";
                continue;
            }
            else if(n==18){
                cout << "1\n";
                cout << "010011010101011010\n";
                continue;
            }
            else if(n==19){
                cout << "0\n";
                cout << "1100110110100111100\n";
                continue;
            }
            else if(n==20){
                cout << "0\n";
                cout << "01011111110111111000\n";
                continue;
            }

            __int128 sum1 = 0;
            __int128 sum2 = 0;

           for(int i=n ; i>20 ; i--){
                if(sum1 > sum2){
                    sum2 += k_power[i];
                    group[i-1] = 1;
                }
                else{
                    sum1 += k_power[i];
                }
            }
            __int128 half_val = n*n*(n+1)*(n+1)/8;
            
            solve_ans = vector<short> (21,0);
            if(n%4==0 || n%4==3){
                ans = 0;
                __int128 target = half_val - sum2;
				//cout << target << "\n";
                find(20,target);
                solve(20,target);
            }
            else{
                ans = 1;
                __int128 target = half_val - sum2;
                if(find(20,target)){
                    solve(20,target);
                }
                else{
                    find(20,target+1);
                    solve(20,target+1);
                }
            }
    
            cout << ans << "\n";
            for(int i=1 ; i<=20 ; i++) cout << solve_ans[i];
            for(int i=20 ; i<n ; i++) cout << group[i];
            cout << "\n";
        }
        else if(k==4){
            __int128 sum1 = 0;
            __int128 sum2 = 0;
            for(int i=n ; i>20 ; i--){
                if(sum1 > sum2){
                    sum2 += k_power[i];
                    group[i-1] = 1;
                }
                else{
                    sum1 += k_power[i];
                }
            }
            ans = LLONG_MAX;
            solve_recur(min(20,n),sum1,sum2);
            reverse(solve_ans.begin(),solve_ans.end());
            cout << ans << "\n";
            for(auto e : solve_ans) cout << e;
            for(int i=20 ; i<n ; i++) cout << group[i];
            cout << "\n";
        }


    }
    return 0;
}

