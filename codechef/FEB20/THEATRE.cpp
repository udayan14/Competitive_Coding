#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	int final_output = 0;
	while(t--){
		int n;
		cin >> n;
		int count[4][4];
		for(int i=0 ; i<4 ; ++i)
			for(int j=0 ; j<4 ; ++j)
				count[i][j] = 0;
		for(int i=0 ; i<n ; ++i){
			char c;
			int in;
			cin >> c >> in;
			count[c-'A'][(in/3)-1]++;
		}
		int output = INT_MIN;
		int a[4] = {0,1,2,3};
		do{
			int temp[4] = {count[0][a[0]],count[1][a[1]],count[2][a[2]],count[3][a[3]]};
			sort(temp,temp+4);
			int temp_val=0;
			for(int i=4 ; i>0 ; --i){
				if(temp[i-1]>0)
					temp_val += temp[i-1]*25*i;
				else{
					temp_val -= 100*i;
					break;
				}
			}
			if(temp_val > output)
				output = temp_val;
		}while(next_permutation(a,a+4));
		cout << output << "\n";
		final_output += output;
	}
		cout << final_output << "\n";
}


