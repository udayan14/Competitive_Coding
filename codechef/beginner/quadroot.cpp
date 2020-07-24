#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	;
	double a,b,c;
	cin >> a >> b >> c;
	double x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
	double x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
	cout << setprecision(10) << x1 << "\n" << x2;
}
