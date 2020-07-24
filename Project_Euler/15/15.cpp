#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void Init(long long int Choose[1001][501]){
int M = 1000000007;

for(int i=0 ; i<1001 ; i++){
	for(int j=0 ; j<=min(i,500) ; j++){
		if(j==0 || j==i)
			Choose[i][j]=1;
		else
			Choose[i][j] = ((Choose[i-1][j-1] % M) + (Choose[i-1][j] % M)) % 1000000007;

	}

}


}
int main() {
	long long int Choose[1001][501];
	memset(Choose,0,sizeof(Choose));
	Init(Choose);
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		int m,n;
		cin >> m >> n;
		cout << Choose[m+n][n] << endl;

	}  
    return 0;
}
