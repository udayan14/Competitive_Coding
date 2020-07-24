#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>


using namespace std;

unordered_map <int,long long int> u;
int prime_arr[80000];

int num_of_digits(int n)
{
	int count = 0;
	while(n!=0){
		count++;
		n=n/10;
	}
	return count;
}

long long int digit_hash(int n)
{
	int arr[10];
	memset(arr,0,sizeof(arr));
	while(n!=0){
	arr[n%10]++;
	n/=10;
	}
	long long int out = 0;
	for(int i=0 ; i<10 ; i++){
		out = out*10 + arr[i];
	}
	return out;
}
void SieveofEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    prime[0] = false;
    prime[1] = false;
    memset(prime, true, sizeof(prime)); 
    memset(prime_arr,0,sizeof(prime_arr));
    int i=0;
    for (int p=2; p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
        	prime_arr[i] = p;
			u.insert(make_pair(p,digit_hash(p)));
        	i++;
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}


int main()
{
SieveofEratosthenes(1000000);
int N,K;
cin >> N >> K;
for(int i=0 ; prime_arr[i] < N ; i++){
	int size_i = num_of_digits(prime_arr[i]);
	for(int j=i+1 ; ;j++){
		if(num_of_digits(prime_arr[j])!=size_i)
			break;
		if(!(u[prime_arr[i]]==u[prime_arr[j]]))
			continue;
		int d = prime_arr[j] - prime_arr[i];
		int a3 = prime_arr[j] + d;
		if(num_of_digits(a3)!=size_i)
			break;
		if(!(u[a3]==u[prime_arr[j]]) || !(binary_search(prime_arr,prime_arr+80000,a3)))
			continue;
		if(K==3){
			cout<<prime_arr[i]<<prime_arr[j]<<a3<<endl;
			continue;
		}
		int a4 = a3 + d;
		if(num_of_digits(a4)!=size_i)
			break;
		if(!(u[prime_arr[i]]==u[a4])|| !(binary_search(prime_arr,prime_arr+80000,a4)))
			continue;
		cout<<prime_arr[i]<<prime_arr[j]<<a3<<a4<<endl;
		


	}

}
}

