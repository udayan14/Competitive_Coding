#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        vector <vector<int>> ind_vec(10);
        for(int i=0 ; i<n ; i++){
            ind_vec[s[i]-'0'].push_back(i);
        }

        int output = n;
        for(int i=0 ; i<10 ; i++){
            for(int j=i+1 ; j<10 ; j++){
                int temp = n;
                if(ind_vec[i].size()==0 && ind_vec[j].size()==0) continue;
                else if(ind_vec[i].size()==0){
                    temp = n - ind_vec[j].size();
                    if(temp < output) output = temp;
                    continue;
                }
                else if(ind_vec[j].size()==0){
                    temp = n - ind_vec[i].size();
                    if(temp < output) output = temp;
                    continue;
                }
                else{
                    temp = n - ind_vec[j].size();
                    if(temp < output) output = temp;
                    temp = n - ind_vec[i].size();
                    if(temp < output) output = temp;
                    int ind1 = 0;
                    int ind2 = 0;
                    temp = (n - ind_vec[i].size()) - ind_vec[j].size();
                    bool flag = true;
                    if(ind_vec[i][0] < ind_vec[j][0])
                        flag = true;
                    else flag = false;
                    while(ind1 < ind_vec[i].size() && ind2 < ind_vec[j].size()){
                        if(flag){
                            if(ind_vec[i][ind1] < ind_vec[j][ind2]){
                                flag = false;
                                ++ind1;
                            }
                            else{
                                ind2++;
                                temp++;
                            }
                        }
                        else{
                            if(ind_vec[i][ind1] > ind_vec[j][ind2]){
                                flag = true;
                                ++ind2;
                            }
                            else{
                                ++ind1;
                                ++temp;
                            }
                        }
                    }
                    while(ind1 < ind_vec[i].size()){
                        if(flag && ((n-temp)%2==1)){
                            temp--;
                            flag = false;
                        }
                        ++ind1;
                        ++temp;
                    }
                    while(ind2 < ind_vec[j].size()){
                        if(!flag && ((n-temp)%2==1)){
                            temp--;
                            flag = true;
                        }
                        ++ind2;
                        ++temp;
                    }
                    if((n-temp)%2==1) temp++;
                    if(temp < output) output = temp;
                }
            }
        }
        cout << output << "\n"; 
    }
    return 0;
}

