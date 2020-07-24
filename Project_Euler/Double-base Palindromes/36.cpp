#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	int len = s.length();
	for (int i = 0; i < len/2; ++i)
	{
		if(s[i]!=s[len-i-1])
			return false;
	}
	return true;
}

string convert_to_base_k(int n, int k){
	string s;
	while(n!=0){
		s.append(to_string(n%k));
		n = n/k;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	int n,k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i < n; ++i)
	{
		if(isPalindrome(to_string(i)) && isPalindrome(convert_to_base_k(i,k)))
			sum+=i;
	}
	cout << sum <<endl;
}
