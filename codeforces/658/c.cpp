#include<iostream>
#include<vector>

using namespace std;

char invert(char c){
    if(c=='0') return '1';
    else return '0';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char a[n];
        char b[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<n ; i++){
            cin >> b[i];
        }
        vector<int> output;
        int start = 0;
        int end = n-1;
        int i = n-1;
        bool order = true;
        while(i>=0){
            if(order){
                if(a[end]==b[i]){
                    end--;
                    i--;
                }
                else{
                    if(start==end){
                        output.push_back(i+1);
                        start++;
                        i--;
                    }
                    else if(a[start]!=a[end]){
                        output.push_back(1);
                        output.push_back(i+1);
                        order = false;
                        start++;
                        i--;
                    }
                    else{
                        output.push_back(i+1);
                        order = false;
                        start++;
                        i--;
                    }
                }
            }
            else{
                if(invert(a[start])==b[i]){
                    start++;
                    i--;
                }
                else{
                    if(start==end){
                        output.push_back(i+1);
                        start++;
                        i--;
                    }
                    else if(a[start]!=a[end]){
                        output.push_back(1);
                        output.push_back(i+1);
                        order = true;
                        end--;
                        i--;
                    }
                    else{
                        output.push_back(i+1);
                        order = true;
                        end--;
                        i--;
                    }
                }
            }
        }
        cout << output.size() << " ";
        for(auto p : output)
            cout << p << " ";
        cout << "\n";
    }
}
