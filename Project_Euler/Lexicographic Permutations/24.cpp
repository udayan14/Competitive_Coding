#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string factorial_base(int n, string s){
	stack <int>  num_stack;
	int i=1;
	while(num_stack.size()!=13){
		int c = n%i;
		n = n/i;
		i++;
		num_stack.push(c);
	}
	string out;
	
	while(!num_stack.empty()){
		
		int t = num_stack.top();
		//cout << t;
		num_stack.pop();
		out.push_back(s[t]);
		s.erase(t,1);
	}

	return out;
}

int main() {
	string s = "abcdefghijklm";
	
	int t;
	cin >> t;
	for(int a0=0; a0<t; a0++){
		int n;
		cin >> n;
		cout << factorial_base(n-1,s) << endl;
	}       
    return 0;
}
