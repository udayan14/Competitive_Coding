#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
# define N 1000001




bool prime[N];

void SieveOfEratosthenes()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

    memset(prime, true, sizeof(prime)); 
    prime[0] = false;
    prime[1] = false;
    for (int p=2; p<N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<N; i += p)
                prime[i] = false;
        }
    }
}

bool isTruncatablePrime(int n){
	int temp1 = n;
	int count = 0;
	while(temp1!=0){
		if(!prime[temp1])
			return false;
		count++;
		temp1 = temp1/10;
	}
	int div = pow(10,count-1);
	for (int i = 0; i < count; ++i)
	{
		if(!prime[n])
			return false;
		n = n%div;
		div = div/10;
	}

	return true;
}

int main()
{


SieveOfEratosthenes();
long long int curr_sum = 0;
int n;
cin >> n;
for (int i = 10; i < n; ++i)
{
	if(prime[i]&&isTruncatablePrime(i)){
		cout << i << " ";
		curr_sum+=i;
	}
}

cout<<curr_sum<<endl;

}