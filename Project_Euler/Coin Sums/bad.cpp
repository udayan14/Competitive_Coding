#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int m = 8;
const int n = 100000;
const int p = 1e9 + 7;
int main(){

	int S[] = {1,2,5,10,20,50,100,200};
	int table[n+1][m];
	/*Geeks for geeks helped a bit here.*/
    int i, j, x, y;
 	
    // We need n+1 rows as the table is consturcted in bottom up manner using 
    // the base case 0 value case (n = 0)
    
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = (x%p + y%p)%p;
        }
    }


	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
        int in;
		cin >> in;
		cout << table[in][m-1] <<endl;
	}
}
