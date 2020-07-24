#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

bool isPermutation(int n1, int n2){
	int a[10];
	memset(a,0,sizeof(a));
	while(n1!=0){
		a[n1%10]++;
		n1/=10;
	}
	while(n2!=0){
		a[n2%10]--;
		n2/=10;
	}
	for(int i=0 ; i<10 ; i++){
		if(a[i]!=0)
			return false;
	}
	return true;



}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N,K;
	cin >> N >> K;
	for(int i = 1 ; i < N ; i++){
		int temp = i;
		int flag = true;
		queue <int> q;
		q.push(i);
		for(int j=2 ; j<K+1 ; j++){
			flag &= isPermutation(temp,j*temp);
			q.push(j*temp);
			if(!flag)
				break;
		}
		if(flag){
			while(!q.empty()){
				cout << q.front() << " ";
				q.pop();
			}
			cout << "\n";
		}

	}
	return 0;
}

