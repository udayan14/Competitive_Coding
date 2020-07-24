#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int alp_value(string s){
	int count = 0;
	for(int i=0; i<s.length(); i++){
		char c = s[i];
		count = count + c - 64;
//		cout << c - 64 << " ";
	}
	return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> stringarray;
    vector<int> score;
    for(int a0=0 ;a0<n; a0++){
        string s;
        cin >> s;
        stringarray.push_back(s);
    }
    sort(stringarray.begin(), stringarray.end());
    for(int a0=0; a0<n; a0++){
    	string s = stringarray[a0];
    	score.push_back((a0+1)*alp_value(s));
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
    	string s;
    	cin >> s;
    	int out = distance(stringarray.begin(),find(stringarray.begin(), stringarray.end(),s));
    	cout << score[out] <<endl;
    }
    return 0;
}
