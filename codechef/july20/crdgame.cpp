#include<iostream>

using namespace std;

int sum_of_digits(int n){
    int output = 0;
    while(n){
        output += n%10;
        n/=10;
    }
    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int morty = 0;
        int chef = 0;
        while(n--){
            int a,b;
            cin >> a >> b;
            if(sum_of_digits(a) >= sum_of_digits(b))
                chef++;
            if(sum_of_digits(a) <= sum_of_digits(b))
                morty++;
        }
        if(chef > morty) cout << 0 << " " << chef << "\n";
        else if (morty > chef) cout << 1 << " " << morty << "\n";
        else cout << 2 << " " << chef << "\n";
    }
}
