#include<cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
# define N 1000001


 bool prime[N];

vector<int> SieveOfEratosthenes()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
	vector<int> prime_vec;
    prime[0] = false;
    prime[1] = false;
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
        	prime_vec.push_back(p);
            // Update all multiples of p
            for (int i=p*2; i<N; i += p)
                prime[i] = false;
        }
    }
	return prime_vec;
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}

int main()
{
	vector<int> prime_vec;
	prime_vec = SieveOfEratosthenes();
	int lim = 55000;
	long long int a[lim];
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=0 ; i<n ; i++)
			a[i] = 1;
		int start = 0;
		int end = n-1;
		//cout << end << " " << prime_vec[end];

		for(int i=0 ; i<n ; i++)
		{
			if(i%2==0)
			{
				if(a[i]*prime_vec[start]>1e9)
					start = 0;
				a[i]*=prime_vec[start];
				a[(i+1)%n]*=prime_vec[start];
				start++;
			}
			else
			{
				if(a[i]*prime_vec[end]>1e9)
				{
					a[(i-1)%n] /= a[i] ;
					a[i] = 2;
					a[(i-1)%n]*=2;
					start = 1;
				}
				a[i]*=prime_vec[end];
				a[(i+1)%n]*=prime_vec[end];
				end--;
			}
		}
   /*     unordered_set <int> check;*/
		//for(int i=0 ; i<n ; i++)
		//{
			//if(a[i]<1 || a[i]>1e9)
				//cout << "Element at index " << i << " does not fit constraint.\n";
			//else if(gcd(a[i],a[(i+1)%n])==1)
				//cout << "Elements are co-prime\n";
			//else if(gcd(gcd(a[i],a[(i+1)%n]),a[(i+2)%n])!=1)
				//cout << "Elements are not co-prime";
			//else if(check.count(a[i])>0)
				//cout << "Element Repeated";
			//check.insert(a[i]);
		/*}*/
		for(int i=0 ; i<n ; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
}
