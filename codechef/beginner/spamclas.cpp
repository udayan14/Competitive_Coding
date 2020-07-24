#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int N,minX,maxX;
		cin >> N >> minX >> maxX;
		int w[N],b[N];
		bool is_grad_even = false;
		int output = minX;
		for(int i=0 ; i<N ; i++){
			cin >> w[i] >> b[i];
			if(w[i]%2==0)
				is_grad_even = true;
				output = (output%2)*(w[i]%2) + b[i]%2;
		}
		if(output%2==0 && is_grad_even)
			cout << maxX - minX + 1 << " " << 0 << "\n";
		else if(output%2==0 && !is_grad_even)
		{
			int spammer = (maxX - minX + 1)/2;
			int non_spammer = maxX - minX + 1 - spammer;
			cout << non_spammer << " " << spammer << "\n";
		}
		else if(output%2!=0 && is_grad_even)
			cout << 0 << " " << maxX - minX + 1 << "\n";
		else
		{
			int non_spammer = (maxX - minX + 1)/2;
			int spammer = maxX - minX + 1 - non_spammer;
			cout << non_spammer << " " << spammer << "\n";
		}

	}
}
