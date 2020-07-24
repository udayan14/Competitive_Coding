#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 5000001
int freq[N];
int output[N];

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0 || b == 0)
       return 0;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     memset(freq,0,sizeof(freq));
    for (int m = 2; m < 1200 ; m++ )
    {
    	for (int n = 1; n < m; ++n)
    	{
    		if(gcd(m,n)==1 && (m+n)%2!=0){
	    		int p = 2 * m * (m+n);
	    		for (int k = 1; ; ++k)
	    		{
	    			if(k*p >= N)
	    				break;
	    			freq[k*p]++;
	    		}
    		}
    	}
    }

    output[0] = 0;
    output[1] = 0;
    for (int i = 2; i < N; ++i)
    {
    	if(freq[i] > freq[output[i-1]])
    		output[i] = i;
    	else output[i] = output[i-1];
    }

    int t;
    cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << output[n] << endl;
	}
// for (int i = 0; i < t; ++i)
// {
// 	cout << i << " " << freq[i] << " " << output[i] << endl;
// }

}
