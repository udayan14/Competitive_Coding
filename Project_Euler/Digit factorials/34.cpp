#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 1000001

int factorial[10];

int digit_factorial_sum(int temp)
{
int sum = 0;
while(temp!=0)
{
	sum += factorial[temp%10];
	temp = temp/10;
}
return sum;
}

int main() 
{

factorial[0] = 1;
for (int i = 1; i < 10; ++i)
{
	factorial[i] = i*factorial[i-1];
}

int curr_sum = 0;

for (int i = 19; i < N; ++i)
{
	if(digit_factorial_sum(i)==i)
		curr_sum+=i;
}

cout << curr_sum << endl;

}
