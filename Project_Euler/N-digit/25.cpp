#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
	for(int i=0 ; i<len ; i++)
	{
		out.push_back(s.top()+'0');
		s.pop();
	}
	return out;
}

void initialize(vector<int> &v){
	string s1 = "1";
	string s2 = "1";
	v.push_back(0);
	v.push_back(1);
	int curr_length = 1;
	int count = 3;
	while(v.size() < 5000)
	{
		string s = Add(s1,s2);
		s1 = s2;
		s2 = s;
		if(s.length() == curr_length + 1)
		{
			curr_length++;
			v.push_back(count);
			//cout << count <<endl;
		}
		count++;
	}
	return;
}

int main() {
  	vector<int> fib_array;
  	// fib_array[0] = 0;
  	// fib_array[1] = 1;
  	initialize(fib_array);
  	int t;
  	cin >> t;
  	for (int i = 0; i < t; ++i)
  	{
  		int n;
  		cin >> n;
  		cout << fib_array[n] << endl;
  	}
    return 0;
}
