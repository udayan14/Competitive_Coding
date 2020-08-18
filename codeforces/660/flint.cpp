#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        vector<long long int> p = {2,3,5,7,11,13,17,19,23,29};
        vector<long long int> nearly_p;
        for(int i=0 ; i<p.size() ; i++){
            for(int j=i+1 ; j<p.size() ; j++){
                nearly_p.push_back(p[i]*p[j]);
            }
        }
        sort(nearly_p.begin(),nearly_p.end());

        bool flag = false;
        for(int i=0 ; i<nearly_p.size() && !flag ; i++){
            for(int j=i+1 ; j<nearly_p.size() && !flag ; j++){
                for(int k=j+1 ; k<nearly_p.size() && !flag ; k++){
                    long long int temp = n - nearly_p[i] - nearly_p[j] - nearly_p[k];
                    if(temp==nearly_p[i] || temp==nearly_p[j] || temp==nearly_p[k] || temp<1)
                        continue;
                    else{
                        flag = true;
                        cout << "YES\n" << nearly_p[i] << " " << nearly_p[j] << " " << nearly_p[k] << " " << temp << "\n"; 
                    }
                }
            }
        }
       if(!flag){ 
            cout << "NO\n";
        }
    }
    return 0;
}

