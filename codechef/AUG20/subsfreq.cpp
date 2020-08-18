#include <bits/stdc++.h>
using namespace std;

const long long int p = 1e9 + 7;

long long int mod_exp(long long int x, long long int y){
    if(x==1) return 1;
    else if(y==0) return 1;
    long long int out = 1;
    while(y){
        if(y&1)
            out = (out*x)%p;
        x = (x*x)%p;
        y >>= 1;
    }
    return out;
}

long long int inv(long long int x){
    return mod_exp(x,p-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> count(n+1,0);
        long long int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            count[in]++;
        }
        vector<long long int> product_of_lt(n+1,1);
        int count_of_counts[n+1];
        memset(count_of_counts,0,sizeof(count_of_counts));

        vector<long long int> output(n+1,0);

        for(auto c : count){
            if(c>0)
                count_of_counts[c]++;
        }
        product_of_lt[0] = 1;
        for(int i=2 ; i<n+1 ; i++){
            product_of_lt[i] = (product_of_lt[i-1] * mod_exp(2,(i-1)*count_of_counts[i-1]))%p;
        }
        vector<long long int> left_mul(n+1,1);
        vector<long long int> right_mul(n+1,1);
        for(int i=1 ; i<n+1 ; i++){
            long long int temp = 1;
            long long int mul = 0;
            for(long long int j=0 ; j<=count[i] ; j++){
                mul += temp;
                if(mul > p ) mul -= p;
                right_mul[j] = (right_mul[j] * mul) %p ;
                temp = (temp * (count[i]-j))%p;
                temp = (temp * inv(j+1))%p;
            }
        }
       /* cout << "right_mul:\n";*/
        //for(auto a : right_mul) cout << a << " ";
        /*cout << "\n";*/
        for(int i=1 ; i<n+1 ; i++){
            long long int mul = 1;
            long long int temp = count[i];
            for(long long int j = 1 ; j<=count[i] ; j++){
                mul += temp;
                if(mul>p) mul -= p;
                right_mul[j] = (right_mul[j] * inv(mul))%p;
                //cout << product_of_lt[j] << " " << right_mul[j] << " " << left_mul[j-1] << " "<< temp << "\n"; 
                output[i] += (((((product_of_lt[j] * right_mul[j])%p)*left_mul[j-1])%p) * temp)%p;
                if(output[i] > p) output[i] -= p;
                temp = (temp *  (count[i]-j))%p;
                temp = (temp * inv(j+1))%p;
            }
            mul = 1;
            temp = count[i];
            for(long long int j=1 ; j<count[i] ; j++){
                mul += temp;
                if(mul > p) mul -= p;
                left_mul[j] = (left_mul[j] * mul) % p; 
                temp = (temp *  (count[i]-j))%p;
                temp = (temp * inv(j+1))%p;
            }
        }
        for(int i=1 ; i < output.size() ; i++)
            cout << output[i] << " ";
        cout << "\n";
    }
	/*int arr[] = {1, 3, 5, 7, 9, 11}; */
	//int n = sizeof(arr)/sizeof(arr[0]); 

	//// Build segment tree from given array 
	//int *st = constructST(arr, n); 

	//// Print sum of values in array from index 1 to 3 
	//cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl; 

	//// Update: set arr[1] = 10 and update corresponding 
	//// segment tree nodes 
	//updateValue(arr, st, n, 1, 10); 

	//// Find sum after the value is updated 
	//cout<<"Updated sum of values in given range = "
			/*<<getSum(st, n, 1, 3)<<endl; */
	return 0;
} 

