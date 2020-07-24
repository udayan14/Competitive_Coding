#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	char board[n][m];
	int max_len = min(m,n);
	int size_subboard[max_len*max_len];
	memset(size_subboard,0,sizeof(size_subboard));
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			cin >> board[i][j];
   /* for(int i=0 ; i<n ; i++)*/
	//{
		//for(int j=0 ; j<n ; j++)
		//{
			//cout << board[i][j];
		//}
		//cout << "\n";
	/*}*/
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0; j<m ; j++)
		{
			int c = 0;
			int white=0;
			int black=0;
			while(i+c<n && j+c<m)
			{
				if((c%2)==0)
				{
					for(int p=i; p<i+c+1 ; p++)
					{
						if((p-i)%2==0)
						{
							if(board[p][j+c]=='0')
								white++;
						}
						else
						{
							if(board[p][j+c]=='1')
								white++;
						}
					}
					for(int q=j ; q<j+c ; q++)
					{
						if((q-j)%2==0)
						{
							if(board[i+c][q]=='0')
								white++;
						}
						else
						{
							if(board[i+c][q]=='1')
								white++;
						}
					}
					black=c*c+2*c+1-white;
				}
				else
				{
					for(int p=i; p<i+c+1 ; p++)
					{
						if((p-i)%2==0)
						{
							if(board[p][j+c]=='1')
								white++;
						}
						else
						{
							if(board[p][j+c]=='0')
								white++;
						}
					}
					for(int q=j ; q<j+c ; q++)
					{
						if((q-j)%2==0)
						{
							if(board[i+c][q]=='1')
								white++;
						}
						else
						{
							if(board[i+c][q]=='0')
								white++;
						}
					}
					black=c*c+2*c+1-white;
				}
				size_subboard[black] = max(c+1,size_subboard[black]);
				size_subboard[white] = max(c+1,size_subboard[white]);
			//	cout << i << " " << j << " " << c << " " << white << " " << black << "\n";
				c++;
			}
		}
	}
	int output[max_len*max_len];
	output[0] = size_subboard[0];
	for(int i=1 ; i<max_len*max_len ; i++)
		output[i] = max(output[i-1],size_subboard[i]);
	int q;
	cin >> q;
	while(q--)
	{
		long long int c_in;
		cin >> c_in;
		if(c_in >= max_len*max_len)
			cout << max_len << "\n";
		else
			cout << output[c_in] << "\n";
		
	}
}
