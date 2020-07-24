#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int cumdigits[18];

int finddigit(long long int n , int k){
	int count = 0;
	long long int temp = n;
	while(temp!=0){
		count++;
		temp = temp / 10;
	}
	int temp2 = count - k - 1;
	while(temp2--){
		n = n/10;
	}
	return n%10;
}

int d(long long int n){
 	int num = 0;
 	while(true){
 		if(cumdigits[num] >= n)
 			break;
 		num++;
 	}
 	long long int temp = (n - cumdigits[num-1] - 1);
 	return finddigit((unsigned long long int)pow(10,num-1) + temp/num,temp%num);	
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    unsigned long long int numdigits[18];
    numdigits[0] = 0;
    cumdigits[0] = 0;
    for (int i = 1; i < 18; ++i)
     {
     	numdigits[i] = (unsigned long long int)9 * i * pow(10,i-1);
     	cumdigits[i] = cumdigits[i-1] + numdigits[i];
     } 
     int t;
     cin >> t;
     while(t--){
     	long long int n1, n2, n3, n4, n5, n6, n7;
     	cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7;
     	cout << d(n1)*d(n2)*d(n3)*d(n4)*d(n5)*d(n6)*d(n7) << endl;
     }
    // for (int i = 0; i < 18; ++i)
    //  {
    //  	cout << i << " " <<numdigits[i] << " " << cumdigits[i]  << endl;
    //  }
    return 0;
}
