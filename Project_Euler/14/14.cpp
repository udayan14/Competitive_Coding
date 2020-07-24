#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

long int collatz_step(long int i){
	if(i%2==0)
		return i/2;
	else return 3*i+1;
}

int fill(long int i, vector<int>&Collatz){
	if(i<5000001){
		if(Collatz[i]==0){
			long int k = collatz_step(i);
			int x = fill(k,Collatz);
			if(i<5000001){
				Collatz[i] = 1 + x;
			}
			return 1 + x;
		}
		else return Collatz[i];
	}
	else return (1 + fill(collatz_step(i),Collatz));
}

int main() {
	vector <int> Collatz(5000001,0);
	vector <int> Output(5000001,0);
	Collatz[1] = 1;
	int curr_max = 1;
	int curr_ind = 1;
	for(int i=1 ; i<5000001 ; i++){
		fill(i,Collatz);
		if(Collatz[i]>=curr_max){
			Output[i] = i;
			curr_ind = i;
			curr_max = Collatz[i];
		}
		else Output[i] = curr_ind;
	}
	int t;
	cin >> t;
	for(int a0=0; a0<t; a0++){
		int x;
		cin >> x;
		cout<<Output[x]<<endl;
	}

}
