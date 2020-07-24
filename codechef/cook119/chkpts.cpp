#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct pt{
    long long int x,y,num;
    pt(long long int a, long long int b):
    x(a),y(b),num(a+b) {}
    bool operator<(const pt &p2){
        return x < p2.x;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n,c;
        cin >> n >> c;
        long long int x,y;
        map<long long int, vector<pt>> counter;
        for(int i=0 ; i<n ; i++){
            cin >> x >> y;
            pt p(x,y);
            counter[x-y].push_back(p);
        }
        int out1 = 0;
        int out2 = 0;
        for(auto &kvpair : counter){
            auto v = kvpair.second;
            map<long long int,vector<pt>> temp;
            for(auto p : v){
                long long int index = ((p.x%c)+c)%c;
                temp[index].push_back(p);
            }
            out1 += temp.size();
            for(const auto &eqclass : temp){
                auto vec = eqclass.second;
                sort(vec.begin(),vec.end());
                long long int checkpt = vec[vec.size()/2].x;
                for(const auto &point : vec){
                    long long int add = point.x - checkpt;
                    if(add < 0 ) add = -add;
                    out2 += add;
                }
            }
        }
        cout << out1 << " " << out2/c << "\n";
    }
}
