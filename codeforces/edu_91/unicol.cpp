#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int count_s = 0;
        int count_r = 0;
        int count_p = 0;
        for(int i=0 ; i<s.length() ; i++){
            switch(s[i]){
                case 'R' :
                    count_r++;
                    break;
                case 'P' :
                    count_p++;
                    break;
                case 'S' :
                    count_s++;
                    break;
            }
        }
        char out;
        if(count_r > count_p){
            if(count_s > count_r){
                out = 'R';
            }
            else{
                out = 'P';
            }
        }
        else{
            if(count_s > count_p)
                out = 'R';
            else
                out = 'S';
        }
        for(int i=0 ; i<s.length() ;i++) cout << out;
        cout << "\n";
    }
}
