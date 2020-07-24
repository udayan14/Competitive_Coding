#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
# define N 1000001


 bool prime[N];

void SieveOfEratosthenes(vector<int> &prime_array)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    prime[0] = false;
    prime[1] = false;
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
        	prime_array.push_back(p);
            // Update all multiples of p
            for (int i=p*2; i<N; i += p)
                prime[i] = false;
        }
    }
}

bool isCircularPrime(int n, vector<int> v){
	int temp1 = n;
	int count = 0;
	while(temp1!=0){
		count++;
		temp1 = temp1/10;
	}
	int mult = pow(10,count-1);
	for (int i = 0; i < count; ++i)
	{
		if(!binary_search(v.begin(), v.end(),n))
			return false;
		n = n/10 + (n%10)*mult;
	}

	return true;
}

int main() {
 vector<int> prime_array;
 SieveOfEratosthenes(prime_array);

 int output[N];
 int curr_sum = 0;
 int euler = 0;
 for (int i = 0; i < N; ++i)
 {
 	output[i] = curr_sum;
 	if(prime[i]&&isCircularPrime(i,prime_array)){
 		curr_sum+=i;
 		euler++;
 	}
 }
 int n;
 cin >> n;
cout<<euler<<endl;

}
