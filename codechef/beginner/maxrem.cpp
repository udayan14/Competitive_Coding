#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	int curr_max = 0;
	for(int i=0 ; i<n ; i++)
	{
		cin >> a[i];
		if(a[i] > curr_max)
			curr_max = a[i];
	}
	int second_max = 0;
	for(int i=0 ; i<n ; i++)
	{
		if(a[i] > second_max && a[i] < curr_max)
			second_max = a[i];
	}
	if(second_max==0)
		cout << 0 << "\n";
	else
		cout << second_max << "\n";
	
}
