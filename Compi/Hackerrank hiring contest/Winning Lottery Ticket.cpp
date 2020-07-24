#include <iostream>
#include <cstring>
using namespace std;



int main()
{
int n;
cin >> n;
int A[n][10];
memset(A,0,sizeof(A));
for (int i = 0; i < n; ++i)
{
	char c;
	while(cin >> c)
	{

		if(c==' ')
			break;
		A[i][c-'0'] = A[i][c-'0'] | 1;
	}

}
int count = 0;
for (int i = 0; i < n-1 ; ++i)
{
	for (int j = i+1; j < n; ++j)
	{
		int check = 1;
		for (int z = 0; z < 10; ++z)
		{
			int out = A[i][z] | A[j][z];
			check = check & out;
		}
		if (check == 1)
		{
			count++;
		}
	}
}
// for (int i = 0; i < n; ++i)
// {
// 	for (int j = 0; j < 10; ++j)
// 	{
// 		cout << A[i][j] <<" ";
// 	}
// 	cout <<"\n";
// }
cout << count << "\n";
}