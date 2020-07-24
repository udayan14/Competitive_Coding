#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,p;
        int x;
        cin >> n >> p;
        cout << 1 << " " << 1 << " " << 1 << " " << n << " " << n << endl;
        cin >> x;
        int count = 0;
        int curr_row = 1;
        int A[n+1][n+1];
        memset(A,0,sizeof(A));
        while(count < 5*n*n){
            if(x==0){
                cout << 2 << "\n";
                for(int i=1 ; i<=n ; i++){
                    for(int j=1 ; j<=n ; j++){
                        cout << A[i][j] << " ";
                    }
                    cout << endl;
                }
                int res;
                cin >> res;
                if(res==-1)
                    return 0;
                break;
            }
            if(curr_row < n){
                cout << 1 << " " << curr_row+1 << " " << 1 << " " << n << " " << n << endl;
                int temp;
                cin >> temp;
                count++;
                if(temp==x){
                    curr_row++;
                    continue;
                }
                else if(x-temp==n){
                    for(int col=1 ; col <= n ; col++)
                        A[curr_row][col] = 1;
                    x = temp;
                    curr_row++;
                }
                else{
                    int diff = x - temp;
                    for(int col = n-1 ; col>=1 ; col--){
                        cout << 1 << " " << curr_row << " " << 1 << " " << curr_row << " " << col << endl;
                        int between;
                        cin >> between;
                        count++;
                        if(between<diff){
                            diff-=1;
                            A[curr_row][col+1] = 1;
                        }
                        if(between==0)
                            break;
                        if(between==col){
                            for(int i=1 ; i<=col ; i++)
                                A[curr_row][i] = 1;
                            break;
                        }
                    }
                    curr_row++;
                    x = temp;
                }
            }
            else{
                for(int col = n-1 ; col>=1 ; col--){
                    cout << 1 << " " << curr_row << " " << 1 << " " << curr_row << " " << col << endl;
                    int between;
                    cin >> between;
                    count++;
                    if(between<x){
                        x--;
                        A[curr_row][col+1] = 1;
                    }
                    if(between==0)
                        break;
                    if(between==col){
                        for(int i=1 ; i<=col ; i++)
                            A[curr_row][i] = 1;
                        x = 0;
                        break;
                    }
                }
            }
        }
    }
}
