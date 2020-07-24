#include<iostream>

using namespace std;

long long int modexp(long long int x, long long int y, long long int p)
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

int main(){
	int t;
	long m = 1e9 + 7;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long arr[n];
		long num = 0;
		for(int i=0 ; i<n ; i++){
			int in;
			cin >> in;
			arr[i] = in;
			num|=in;
		}
		//cout << num << "\n";
		long i = 1;
		long long out = 0;
		int count = 0;
		for( ; num/i ; i<<=1){
			if((num&i)!=0){
				//cout << "Here" << "\n";
				out = (out + modexp(2 , n+count-1 , m))%m;
			}
			count++;
		}
	cout << out << "\n";
	}
}

