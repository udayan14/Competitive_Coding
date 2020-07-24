#include<iostream>
#include<cstring>
using namespace std;

const int A_max = 2001;
int tree[2*A_max];

// Implementation of segment tree has been copied from geeksforgeeks
//
// function to build the tree 
void build()  
{  
    memset(tree,0,sizeof(tree));  
} 
  
// function to update a tree node 
void updateTreeNode(int p, int value)  
{  
    // set value at position p 
    tree[p+A_max] = value; 
    p = p+A_max; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
  
// function to get sum on interval [l, r) 
int query(int l, int r)  
{  
	
    int res = 0; 
      
    for (l += A_max, r += A_max; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
      
        if (r&1)  
            res += tree[--r]; 
    } 
      
    return res; 
} 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i=0 ; i<n ; i++)
			cin >> a[i];

		long long int freq[A_max];
		int output = 0;
		for(int i=0 ; i<n ; i++)
		{
			build();
			memset(freq,0,sizeof(freq));
			for(int j=i ; j<n ; j++)
			{
				freq[a[j]]++;
				updateTreeNode(a[j],freq[a[j]]);
				int length = j-i+1;
				int mult;
				if(k%length==0)
					mult = k/length;
				else
					mult = k/length + 1;
				long long int count = 0;
				int index=-1;
				int low = 0;
				int high = A_max-1;
				while(low<=high)
				{
					int mid = low + (high-low+1)/2;
					int midVal = query(0,mid+1);
					if(mult*midVal<k)
					{
						index = mid;
						low = mid+1;
					}
					else if(mult*midVal>k)
					{
						high = mid-1;
					}
					else
					{
						high = mid-1;
					}
				}
				int x = index+1;
				int f = freq[x];
				if(freq[f]>0)
					output++;
			}
		}
		cout << output << "\n";
	}
}
