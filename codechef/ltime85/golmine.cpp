#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        double g1 = 0.0;
        double g2 = 0.0;
        int n;
        cin >> n;
        while(n--){
            int g, a, b;
            cin >> g >> a >> b;
            double r1 = g/(1.0*a);
            double r2 = g/(1.0*b);
            double tot_days = g/(r1 + r2);
            g1 += tot_days * r1;
            g2 += tot_days * r2;
        }
        cout << setprecision(10) << g1 << " " << g2 << "\n";
    }
}
