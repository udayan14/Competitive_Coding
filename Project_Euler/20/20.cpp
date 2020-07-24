#include <iostream>
#include <string>
#include <stack>

using namespace std;

string Add(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 < len2)
		s1 = string(len2 - len1 , '0').append(s1);
	else if(len1 > len2)
		s2 = string(len1 - len2 , '0').append(s2);
	int carry = 0;
	int l = s1.length();
	stack <int> s;
	for(int i=l-1 ; i>=0 ; i--){
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

string Multiply_single(string s1, char c){
	int len = s1.length();
	if(len == 0) return "0";
	int carry = 0;
	int single_num = c - '0';
	stack<int> s;
	for(int i = len-1; i>=0 ; i--){
		int num = s1[i] - '0';
		int out = (num * single_num + carry)%10;
		carry = (num * single_num + carry)/10;
		s.push(out);
	}
	if(carry!=0)
		s.push(carry);
	string out;
	int stack_size = s.size();
	for(int i=0 ; i<stack_size ; i++){
		out.push_back(s.top()+'0');
		s.pop();
	}
	return out;
}

string Multiply(string s1, string s2){
	int len = s1.length();
	string out = "";
	for(int i=0 ; i<len ; i++){
		out = Add(out,Multiply_single(s2,s1[i]) + string(len - 1 - i,'0'));
	}
	return out;
}
int Digit_Sum(string s){
	int out = 0;
	int len = s.length();
	for(int i=0 ; i<len ; i++){
		out += s[i] - '0';
	}
	return out;
}

string factorial(int n){
	string out = "1";
	for(int i=1 ; i<=n ; i++){
		out = Multiply(to_string(i),out);
	}
	return out;
}


////****O(1) lookup****/////

int main(){
	int output[1001];
	output[0] = 1;
	string fact = "1";
	for(int i=1 ; i<1001 ;i++){
		fact = Multiply(to_string(i),fact);
		output[i] = Digit_Sum(fact);
	}
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
		int n;
		cin >> n;
		cout << output[n]<<endl;
	}
}