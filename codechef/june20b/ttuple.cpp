#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int p,q,r;
        cin >> p >> q >> r;
        long long int a,b,c;
        cin >> a >> b >> c;
        vector<pair<long long,long long>> tmp;
        tmp.clear();
        if(p!=a)    tmp.push_back(make_pair(p,a));
        if(q!=b)    tmp.push_back(make_pair(q,b));
        if(r!=c)    tmp.push_back(make_pair(r,c));
        short output = tmp.size();
        if(tmp.size()==2){
            long long int x1,x2,y1,y2;
            x1 = tmp[0].first;
            y1 = tmp[0].second;
            x2 = tmp[1].first;
            y2 = tmp[1].second;
            long long int diff = y1 - x1;
            if(y2-x2==diff)
                output = 1;
            else if((x1==0) || (x2==0))
                output = 2;
            else if(y1%x1==0){
                long long int factor = y1/x1;
                if(y2==x2*factor)
                    output = 1;
            }
        }
        else if(tmp.size()==3){
            long long int x1,x2,x3,y1,y2,y3;
            x1 = tmp[0].first;
            y1 = tmp[0].second;
            x2 = tmp[1].first;
            y2 = tmp[1].second;
            x3 = tmp[2].first;
            y3 = tmp[2].second;
            long long int diff1 = y1-x1;
            long long int diff2 = y2-x2;
            long long int diff3 = y3-x3;
            bool f1 = false;
            bool f2 = false;
            bool f3 = false;
            if(x1) f1 = (y1%x1==0);
            if(x2) f2 = (y2%x2==0);
            if(x3) f3 = (y3%x3==0);
            //long long int diff_arr[3] = {diff1,diff2,diff3};

            long long int factor1 = INT_MAX;
            long long int factor2 = INT_MAX;
            long long int factor3 = INT_MAX;

            if(x1) factor1 = y1/x1;
            if(x2) factor2 = y2/x2;
            if(x3) factor3 = y3/x3;
            long long int factor_arr[3] = {factor1,factor2,factor3};

            sort(factor_arr,factor_arr+3);

            if((diff1==diff2)&&(diff2==diff3))
                output = 1;
            else if(f1&&(y2==factor1*x2)&&(y3==factor1*x3))
                output=1;
            else if((diff1+diff2==diff3)||(diff2+diff3==diff1)||(diff3+diff1==diff2)||(diff1==diff2)||(diff2==diff3)||(diff1==diff3)){
                output = 2;
            }
            else if(f1 && f2 && f3 && ((factor_arr[0]=factor_arr[1]*factor_arr[2])||(factor_arr[2]=factor_arr[0]*factor_arr[1]))){
                output = 2;
            }
            else if((f1&&f2&&(factor1==factor2))||(f2&&f3&&(factor2==factor3))||(f1&&f3&&(factor1==factor3))){
                output = 2;
            }
            else{
                long long int del_y_12 = y1 - y2;
                long long int del_y_23 = y2 - y3;
                long long int del_y_31 = y3 - y1;
                long long int del_x_12 = x1 - x2;
                long long int del_x_23 = x2 - x3;
                long long int del_x_31 = x3 - x1;
                bool g12 = false;
                bool g23 = false;
                bool g31 = false;
                if(del_x_12) g12 = (del_y_12%del_x_12==0);
                if(del_x_23) g23 = (del_y_23%del_x_23==0);
                if(del_x_31) g31 = (del_y_31%del_x_31==0);
                long long int fct12 = INT_MAX;
                long long int fct23 = INT_MAX;
                long long int fct31 = INT_MAX;
                if(del_x_12) fct12 = del_y_12/del_x_12;
                if(del_x_23) fct23 = del_y_23/del_x_23;
                if(del_x_31) fct31 = del_y_31/del_x_31;
                long long int add_term = INT_MAX;
                bool add_before = false;
                if(g12 && g23 && g31 && (fct12==fct23) && (fct23==fct31)){
                    long long int r1 = y1 - fct12*x1;
                    long long int r2 = y2 - fct12*x2;
                    long long int r3 = y3 - fct12*x3;
                    if((r1==r2)&&(r2==r3))
                        output = 2;
                }
                else if(g12){
                    long long int r1 = y1 - fct12*x1;
                    long long int r2 = y2 - fct12*x2;
                    if(fct12) add_term = r1/fct12;
                    if(fct12) add_before = (r1%fct12==0);
                    if((r1==r2) && (r1==diff3))
                        output = 2;
                    else if((r1==r2) && f3 && (factor3==fct12))
                        output = 2;
                    else if(add_before && (r1==r2) && (add_term==diff3))
                        output = 2;
                    else if(add_before && (r1==r2) && f3 && (factor3==fct12))
                        output = 2;
                }
                else if(g23){
                    long long int r2 = y2 - fct23*x2;
                    long long int r3 = y3 - fct23*x3;
                    if(fct23) add_term = r2/fct23;
                    if(fct23) add_before = (r2%fct23==0);
                    if((r2==r3) && (r2==diff1))
                        output = 2;
                    else if((r2==r3) && f1 && (factor1==fct23))
                        output = 2;
                    else if(add_before && (r2==r3) && (add_term==diff1))
                        output = 2;
                    else if(add_before && (r2==r3) && f1 && (factor1==fct23))
                        output = 2;
                }
                else if(g31){
                    long long int r3 = y3 - fct31*x3;
                    long long int r1 = y1 - fct31*x1;
                    if(fct31) add_term = r3/fct31;
                    if(fct31) add_before = (r3%fct31==0);
                    if((r3==r1) && (r3==diff2))
                        output = 2;
                    else if((r3==r1) && f2 && (factor2==fct31))
                        output = 2;
                    else if(add_before && (r3==r1) && (add_term==diff2))
                        output = 2;
                    else if(add_before && (r3==r1) && f2 && (factor2==fct31))
                        output = 2;
                }

            }
        }
        cout << output << "\n";
    }
}
