#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int length(long long int n){
	int count = 0;
	while(n!=0){
		count++;
		n=n/10;
	}
	return count;
}

long long int combine(int i1, int i2){
	return i1*pow(10,length(i2)) + i2;
}

bool ispandigital(long long int n, int k){
	set<int> a;
	pair<set<int>::iterator,bool> ret;
	int count=0;
	if(n%9!=0) return false;
	while(n!=0){
		int m = n%10;
		if(m==0 || m==k+1)
			return false;
		ret = a.insert(m);
		if(ret.second==false)
			return false;
		count++;
		n = n/10;
	}
	if(count==k)
		return true;
	return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin >> n >> k;
    vector<int> output;
    for (int i = 2; i < n; ++i)
    {
    	long long int count = 0;
    	for (int j = 1; j<10 ; ++j)
    	{
    		count = combine(count,i*j);
    		//cout << count << endl;
    		if(length(count)>=k)
    			break;
    	}
    	if(ispandigital(count,k)){
    		output.push_back(i);
    		cout << count << endl;
    	}
    }
    for (int i = 0; i < output.size(); ++i)
    {
    	//cout << output[i] << endl;
    }
    

    return 0;
}
