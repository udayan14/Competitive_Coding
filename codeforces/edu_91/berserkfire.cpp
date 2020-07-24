#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    long long int x,k,y;
    cin >> x >> k >> y;
    int a[n];
    int b[m];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i=0 ; i<m ; i++){
        cin >> b[i];
    }
    if(m>n){
        cout << "=1\n";
        return 0;
    }
    int p1 = 0;
    int p2 = 0;
    int l = 0;
    int r = 0;
    int count = 0;
    int curr_max = 0;
    long long int output = 0;
    bool all_berserk = (x >= k*y);     // Using brserk k times is better a fireball
    while(p1<n && p2<m){
        if(a[p1]==b[p2]){
            r = a[p1];
            if(count>0){
                if(curr_max < max(l,r)){
                    //berserking everything works
                    if(all_berserk){
                        long long int temp = count * y;
                        //cout << "Case 1: "<< temp << "\n";
                        output += temp;
                    }
                    else{
                        long long int temp = x * (count/k) + y * (count%k);
                        //cout << "Case 2: "<< temp << "\n";
                        output += temp;
                    }
                }
                else{
                    //Cannot berserk max value
                    if(count < k){
                        // Not possible
                        cout << "-1\n";
                        return 0;
                    }
                    if(all_berserk){
                        long long int temp = x + (count-k)*y;
                        //cout << "Case 3: "<< temp << "\n";
                        output += temp;
                    }
                    else{
                        long long int temp = x * (count/k) + y*(count%k);
                        //cout << "Case 4: "<< temp << "\n";
                        output += temp;
                    }
                }
            }
            count = 0;
            curr_max = 0;
            l = a[p1];
            p1++;
            p2++;
        }
        else{
            if(a[p1]>curr_max) curr_max = a[p1];
            p1++;
            count++;
        }
    }
    if(p2<m){
        //Couldn't match all values in b
        cout << "-1\n";
        return 0;
    }
    for(int i=p1 ; i<n ; i++){
        if(curr_max < a[i]) curr_max = a[i];
        count++;
    }
    r = 0;
    if(count>0){
        if(curr_max < max(l,r)){
            //berserking everything works
            if(all_berserk){
                long long int temp = count * y;
                output += temp;
            }
            else{
                long long int temp = x * (count/k) + y * (count%k);
                output += temp;
            }
        }
        else{
            //Cannot berserk max value
            if(count < k){
                // Not possible
                cout << "-1\n";
                return 0;
            }
            if(all_berserk){
                long long int temp = x + (count-k)*y;
                output += temp;
            }
            else{
                long long int temp = x * (count/k) + y*(count%k);
                output += temp;
            }
        }
    }
    cout << output << "\n";
}
