#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//Some changes made to solve actual project Euler problem.

int percount(string s){
	int count = 0;
	for(int i=0 ; i<s.length() ; i++){
		if(s[i]!=' ')
			count++;
	}
	return count;
}

string spell(string s){
	if(s=="1")
		return "One";
	else if (s=="2")
		return "Two";
	else if (s=="3")
		return "Three";
	else if (s=="4")
		return "Four";
	else if (s=="5")
		return "Five";
	else if (s=="6")
		return "Six";
	else if (s=="7")
		return "Seven";
	else if (s=="8")
		return "Eight";
	else if (s=="9")
		return "Nine";
	else if (s=="10")
		return "Ten";
	else if (s=="11")
		return "Eleven";
	else if (s=="12")
		return "Twelve";
	else if (s=="13")
		return "Thirteen";
	else if (s=="14")
		return "Fourteen";
	else if (s=="15")
		return "Fifteen";
	else if (s=="16")
		return "Sixteen";
	else if (s=="17")
		return "Seventeen";
	else if (s=="18")
		return "Eighteen";
	else if (s=="19")
		return "Nineteen";
	else if (s=="20")
		return "Twenty";
	else if (s=="30")
		return "Thirty";
	else if (s=="40")
		return "Forty";
	else if (s=="50")
		return "Fifty";
	else if (s=="60")
		return "Sixty";
	else if (s=="70")
		return "Seventy";
	else if (s=="80")
		return "Eighty";
	else if (s=="90")
		return "Ninety";
	else return "";
}

string spell_helper(string s, string app){
	string out = "";
	if(s[0]=='0'){
		if(s[1]=='0'){
			if(s[2]=='0'){
				return "";
			}
			else
				out = spell(s.substr(2,1));
		}
		else if(s[1]=='1'){
			out = spell(s.substr(1,2));
		}
		else{
			if(s[2]=='0')
				out = spell(s.substr(1,2));
			else
				out = spell(s.substr(1,1) + "0") +" "+ spell(s.substr(2,1));
		}

	}
	else{
		out = out + spell(s.substr(0,1)) + " Hundred";
		if(s[1]=='0'){
			if(s[2]=='0'){
				
			}
			else
				out += " and "+spell(s.substr(2,1));
		}
		else if(s[1]=='1'){
			out += " and "+spell(s.substr(1,2));
		}
		else{
			if(s[2]=='0')
				out += " and "+spell(s.substr(1,2));
			else
				out += " and "+spell(s.substr(1,1) + "0") +" "+spell(s.substr(2,1));
		}

	}
	return out + " " + app + " ";
}

string num_to_words(long int n){
	if(n==0){
		return "Zero";
	}
	else if(n==1000000000000)
		return "One Trillion";
	string s = to_string(n);
	int len = s.length();
	string zeros = "";
	for(int i=0; i < 12 - len;i++){
		zeros = zeros + "0";
	}
	s = zeros + s;
	string s1 = s.substr(0,3);
	string s2 = s.substr(3,3);
	string s3 = s.substr(6,3);
	string s4 = s.substr(9,3);
	string out;
	out = spell_helper(s1,"Billion") + spell_helper(s2,"Million") +spell_helper(s3,"Thousand") +spell_helper(s4,""); 
	return out;

}


int main() {
	// int t;
	// long int in;
	// cin >> t;
	// for(int i=0 ; i<t ; i++){
	// 	cin >> in;
	// 	cout << num_to_words(in);
	// }
	int l;
	cin >> l;
	int out = 0;
	for(int i=0 ; i<l ; i++){
		out+= percount(num_to_words(i));
	}
	cout << out;
}
