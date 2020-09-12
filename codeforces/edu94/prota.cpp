//#define _GLIBCXX_DEBUG

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
        int p,f;
        cin >> p >> f;
        int cnt_s, cnt_w;
        cin >> cnt_s >> cnt_w;
        int s, w;
        cin >> s >> w;

        if(s > w){
            swap(s,w);
            swap(cnt_s,cnt_w);
        }
        if(p>f) swap(p,f);
        long long int out = 0;

        for(int i=0 ; i<=cnt_s; i++){
            if(i*s > p) break;
            int second = min(cnt_s-i,f/s);

            int ax1 = min(cnt_w,(p - i*s)/w);
            int ax2 = min(cnt_w-ax1,(f - second*s)/w);

            long long int temp = ax1 + ax2 + i + second;
            if(temp > out) out = temp;
        }
        for(int i=0 ; i<=cnt_s; i++){
            if(i*s > f) break;
            int second = min(cnt_s-i,p/s);

            int ax1 = min(cnt_w,(f - i*s)/w);
            int ax2 = min(cnt_w-ax1,(p - second*s)/w);

            long long int temp = ax1 + ax2 + i + second;
            if(temp > out) out = temp;
        }


        cout << out << "\n";
    }
    return 0;
}

