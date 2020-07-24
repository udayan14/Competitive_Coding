#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		if(k<4)
		{
			cout << -1 << "\n";
			continue;
		}
		map<int,int> counter;
		counter.clear();
		for(int i=0 ; i<n ; i++)
		{
			int in;
			cin >> in;
			counter[in]++;
		}
		int sz = counter.size();
		if(sz+1>=k)
		{
			cout << -1 << "\n";
			continue;
		}
		int arr[sz];
		map<int,int>::iterator it;
		it = counter.begin();
		for(int i=0 ; i<sz ; i++)
		{
			arr[i] = it->first;
			it++;
		}
		sort(arr,arr+sz);
		//for(int i=0 ; i<sz ; i++)
			//cout << arr[i] << " ";
		//cout << "\n";
		unsigned long long int side1, side2;
		bool is_square=false;
		bool side1_found=false;
		bool side2_found=false;
		for(int i=0 ; i<sz ; i++)
		{
			if(counter[arr[i]]>3 && !side1_found)
			{
				side1 = arr[i];
				is_square = true;
				cout << side1*side1 << "\n";
				break;
			}
			else if(counter[arr[i]]>2 && !side1_found)
			{
				side1 = arr[i];
				side1_found = true;
			}
			else if(counter[arr[i]]>2 && side1_found)
			{
				side2 = arr[i];
				cout << side1 * side2 << "\n";
				side2_found=true;
				break;
			}
		}
		if(!is_square && !side2_found)
			cout << -1 << "\n";
	}
}
