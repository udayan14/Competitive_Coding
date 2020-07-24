#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int * prices;
bool sorter(const int& a, const int& b) {
		return (prices[a] < prices[b]);
	}

int main()
 {
	int n;
	cin >> n;
	prices = (int *)malloc(sizeof(int) * n);
	int brands[n];
	int indices[n];
	int sort_brands[n];
	for (int i = 0; i < n; ++i)
	  {
		int p;
		cin >> p;
		brands[i] = p;
	  } 
	for (int i = 0; i < n; ++i)
	  {
		int p;
		cin >> p;
		prices[i] = p;
		indices[i] = i;
	  }  

	sort(indices, indices + n,sorter);
	  for (int i = 0; i < n; ++i)
	  {
		sort_brands[i] = brands[indices[i]];
	  }
	int q;
	cin >> q;
	while(q--){
		int d;
		cin >> d;
		int brand_list[d];
		for (int i = 0; i < d; ++i)
		{
			int in;
			cin >> in;
			brand_list[i] = in;
		}
		int k;
		cin >> k;
		int count = 0;
		bool found = false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < d; ++j)
			{
				if(sort_brands[i]==brand_list[j]){
					count++;
					break;
				}
			}
			if(count==k){
				cout << prices[indices[i]] << endl;
				found = true;
				break;

			}
		}
		if (!found)
			cout << -1 << endl;
	   }
}
