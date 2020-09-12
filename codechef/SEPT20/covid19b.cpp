//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int simulate(int index, const vector<int> &v){
    int n = (int) v.size();
    vector<int> infected(n,0);
    infected[index] = 1;
    double time_step = 1e-2;
    vector<double> pos(n);
    for(int i=0 ; i<n ; i++) pos[i] = i;
    double total_time = 5.0;
    double curr_time = 0.0;
    while(curr_time < total_time){
        for(int i=0 ; i<n ; i++) pos[i] += time_step*v[i];
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(fabs(pos[i]-pos[j]) < 6e-2 && (infected[i] | infected[j])){
                    infected[i] = 1;
                    infected[j] = 1;
                }
            }
        }
        curr_time += time_step;
    }
    int out = 0;
    for(int i=0 ; i<n ; i++) out += infected[i];
    return out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0 ; i<n ; i++){
            cin >> v[i];
        }
        vector<int> num_infected(n);
        for(int i=0 ; i<n ; i++){
            num_infected[i] = simulate(i,v);
        }
        auto result = minmax_element(num_infected.begin(),num_infected.end());
        cout << *result.first << " " << *result.second << "\n";
    }
    return 0;
}

