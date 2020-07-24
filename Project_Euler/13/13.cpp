#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


string add_char(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();

	if(len1==0)
		return s2;
	else{
		string prefix = "";
		for(int i=0; i<len1 - len2; i++){
			prefix = prefix + "0";
		}
		s2 = prefix + s2;
		stack <int> s;
		int carry = 0;
		for(int i=s1.length()-1 ; i>=0 ; i--){
			int num1 = s1[i] - '0';
			int num2 = s2[i] - '0';	
			int out = (num1 + num2 + carry)%10;
			s.push(out);
			carry = (num1 + num2 + carry)/10;
		}
		if(carry!=0)
			s.push(carry);
		string out;
		int len = s.size();
		for(int i=0 ; i<len ; i++){
			out.push_back(s.top()+'0');
			s.pop();
		}
		return out;

	}
}

void handle(int n){
	string temp = "";
	for(int i=0 ;i<n ;i++){
		string s;
		cin >> s;
		temp = add_char(temp,s);

	}
	cout << temp <<endl;
}

int main() {
    int t;
    cin >> t;
    handle(t);
    return 0;
}
