#include<iostream>

using namespace std;

long long int dp[4801];

int solve(int m, int y){
	long long int out = (y/400) * dp[4800];
	out += dp[y%400*12 + m - 1];
	return out;
}

bool isLeap(int year){
	if((year%400)==0)
		return true;
	if((year%4)==0 && (year%100)!=0)
		return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s = 6;
	for(int i=0 ; i<400 ; i++){
		for(int m=1 ; m<=12 ; m++){
			int days;
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
				days = 31;
			else if(m!=2)
				days = 30;
			else if(isLeap(i))
				days = 29;
			else
				days = 28;
			int d1 = 0;
			int dn = days-1;
			while((s+d1)%7 != 5)
				d1++;
			while((s+dn)%7)
				dn--;
			dn -= 7;
			dp[12*i+m] = dp[12*i+m-1] + (d1+10 > dn);
			s = (s+days) % 7;
		}
	}
	int t;
	cin >> t;
	while(t--){
		int m1,y1,m2,y2;
		cin >> m1 >> y1 >> m2 >> y2;
		m2++;
		if(m2==13){
			m2 = 1;
			y2++;
		}
		cout << solve(m2,y2) - solve(m1,y1) << "\n";
	}
}
