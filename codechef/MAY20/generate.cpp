#include<iostream>
#include<time.h>

using namespace std;

int main(){
    int t = 100;
    cout << t << "\n";
    for(int i = 0 ; i<t ; i++){
        cout << rand() << " " << rand() << " " << 0 << " " << rand()%1000000 << "\n";
    }
}
