#include<iostream>
#include<cstring>
#include<list>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n,x;
        cin >> n >> x;
        long long int a[n+1];
        a[0] = 0;
        long long int in;
        long long int m[1000001];
        memset(m,0,sizeof(m));
        for(int i=1 ; i<n+1 ; i++){
            cin >> in;
            a[i] = a[i-1] + in;
        }
        list<pair<long long int,long long int> > validSides;
        for(int side =1 ; side <= sqrt(x) ; side++){
            if(x%side==0){
                long long int temp = x/side;
                validSides.push_back(make_pair(side,temp));
                if(side!=temp){
                    validSides.push_back(make_pair(temp,side));
                }
            }
        }
        long long int output = 0;
        for(const auto & p : validSides){
            long long int side = p.first;
            long long int rem = p.second;
            int i=1;
            while(i+side-1<=n){
                long long int temp = a[i+side-1] - a[i-1];
                if(temp <= rem)
                    m[temp]++;
                i++;
            }
            
            i=1;
            while(i+side-1<=n){
                long long int temp = a[i+side-1] - a[i-1];
                if(temp <= rem)
                    output += m[rem-temp];
                i++;
            }

            i=1;
            while(i+side-1<=n){
                long long int temp = a[i+side-1] - a[i-1];
                if(temp <= rem)
                    m[temp]=0;
                i++;
            }

        }
        cout << output << "\n";
    }
}
