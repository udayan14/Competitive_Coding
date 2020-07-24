#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main(){

	int n;
	cin >> n;
	long int win = (1<<10)-1;
	long count[1024];
	memset(count,0,sizeof(count));
	while(n--){
		string s;
		cin >> s;
		int num = 0;
		for(int i=0 ; i<s.length() ; i++){
			int index = s[i] - '0';
			num |= 1 << index;
		}
		count[num]++;
	}
	unsigned long long output = 0;
	for(int i=0 ; i<1024 ; i++){
		for(int j=i+1 ; j<1024 ; j++){
			if((i|j)==win){
				output += count[i]*count[j];
			}
		}
	}
	output = output + count[win]*(count[win]-1)/2;
	cout << output << "\n";
}
