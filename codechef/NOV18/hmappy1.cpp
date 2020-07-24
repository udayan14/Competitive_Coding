#include<iostream>

using namespace std;

int main()
{
	int n,q,k;
	cin >> n >> q >> k;
	int a[n];
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	int start;
	int flag = 0;
	for(int i=0 ; i<n ; i++)
	{
		if(a[i]==0)
		{
			start = i;
			flag = 1;
			break;
		}
	}
   /* cout << start << "\n";*/
	int count = 0;
	int max_l = -1;
	int max_r = -1;
	int second_max_l = -1;
	int second_max_r = -1;
	int len_max = 0;
	int len_second_max = 0;
	int flag1 = 0;
	int len_counter = 0;
	int curr_start = -1;
	int curr_end = -1;
	while(flag && count<=n)
	{
		if(a[start]==1)
		{
			if(!flag1)
			{
				flag1 = 1;
				curr_start = start;
				len_counter++;
			}
			else
				len_counter++;
		}
		else
		{
			if(flag1)
			{
				flag1 = 0;
				curr_end = start-1;
				if(curr_end<0) curr_end=n-1;
				if(len_counter>len_max)
				{
					max_l = curr_start;
					max_r = curr_end;
					len_max = len_counter;
				}
				else if(len_counter>len_second_max)
				{
					second_max_l = curr_start;
					second_max_r = curr_end;
					len_second_max = len_counter;
				}
				len_counter=0;
			}
		}
		start++;
		if(start==n) start=0;
		count++;
	}
	//cout << "Contiguous Subsequence of length " << len_max << " from " << max_l << " to " << max_r << "\n";
	//cout << "Contiguous Subsequence of length " << len_second_max << " from " << second_max_l << " to " << second_max_r << "\n";
	int index = 0;
	for(int i=0 ; i<q ; i++)
	{
		char c;
		cin >> c;
		if(c=='!')
		{
			index--;
			if(index<0) index = n-1;
		}
		else if(c=='?')
		{
			//cout << index << " " << max_l << " " << max_r << " ";
			if(!flag)
				cout << min(k,n) << "\n";
			else if(max_l <= max_r)
			{
				if(index<=max_l || index>max_r)
					cout << min(k,len_max) << "\n";
				else
					cout << min(k,max(len_second_max,max(max_r-index+1,index-max_l))) << "\n";
			}
			else
			{
				if(index>max_r && index<=max_l)
					cout << min(k,len_max) << "\n";
				else
				{
					if(index>max_l)
						cout << min(k,max(len_second_max,max(index-max_l,n-index+max_r+1))) << "\n";
					else
						cout << min(k,max(len_second_max,max(max_r-index+1,index+n-max_l))) << "\n";
				}
				
			}
		}
	}
}
