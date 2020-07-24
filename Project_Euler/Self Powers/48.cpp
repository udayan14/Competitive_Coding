#include <iostream>
#include <cstring>

using namespace std;

int output[2000001];
long long int m = 10000000000;
long long int modexp(int x, int y, long long int p)
{
    long long int out = 1;
    x = x % p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            out = ((out%p)*(x%p)) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = ((x%p)*(x%p)) % p;  
    }
    return out;
}


int main()
{
	memset(output,0,sizeof(output));
	for (int i = 1; i < 2000001; i++)
	{
		output[i] = (output[i-1]%m + modexp(i,i,m))%m;
	}
	int N;
	cin >> N;
	cout << output[N] << endl;


}
