#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


struct volcano{
    int x;
    int y;
    int weight;
    volcano(int a, int b, int c){
        x = a;
        y = b;
        weight = c;
    }
};

int main() {
    int n;
    cin >> n;
    int lava[n][n];
    vector <volcano> volcano_list; 
    memset(lava,0,sizeof(lava));
    int m;
    cin >> m;
    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        int w;
        cin >> x >> y >> w;
        volcano_list.push_back(volcano(x,y,w));

    }
    int max = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<volcano_list.size() ; k++){
                volcano v = volcano_list[k];
                lava[i][j] += max(0,v.weight - max(abs(i-v.x),abs(j-v.y)));
            }
            if(lava[i][j] > max)
                max = lava[i][j];
        }
    }
    cout << max << endl;

    return 0;
}
