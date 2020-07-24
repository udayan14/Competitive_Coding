#include<iostream>
#include<bitset>

using namespace std;

typedef unsigned long long int ull;

ull naive_solve(ull x, ull y, ull l, ull r){
    ull max_val = (x&l)*(y&l);
    ull curr_val = max_val;
    ull max_index = l;
    for(ull i=l+1 ; i<=r ; i++){
        curr_val = (x&i)*(y&i);
        if(curr_val > max_val){
            max_val = curr_val;
            max_index = i;
        }
    }
    return max_index;
}

ull MSB(ull n){
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n++;
    return (n>>1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        unsigned long long int x,y,l,r;
        cin >> x >> y >> l >> r;
        if(x>y)
            swap(x,y);
        //cout << "The actual output is " << naive_solve(x,y,l,r) << "\n";
        if(x==0){
            cout << l << "\n";
            continue;
        }
        ull temp = (x|y);
        ull index = MSB(r);
        ull curr_val = (x&r)*(y&r);
        ull max_val = curr_val;
        ull curr_output = r & temp;
        ull max_output = curr_output;
        ull history = 0;
        //cout << "MSB of r is " << index << "\n";
        //cout << temp << " values of temp\n";
        while(index > 0){
            if(r&index){
                curr_output = (history | (index-1)) & temp;
                curr_val = (x&curr_output)*(y&curr_output);
                //cout << "looping over index :" << index << "\n";
                if(curr_val > max_val){
                    max_val = curr_val;
                    max_output = curr_output;
                    //cout << max_output << "# \n";
                }
                if(temp&index)
                    history |= index;
            }
            index = index >> 1;
        }
        //cout << history << "\n";
        cout << max_output << "\n";
        ull actual_output = naive_solve(x,y,l,r);
        if(max_output!=actual_output){
            bitset<64> temp_b(temp);
            bitset<64> actual_output_b(actual_output);
            bitset<64> max_output_b(max_output);
            bitset<64> r_b(r); 
            cout << temp_b << "\n";
            cout << r_b << " r\n";
            cout << actual_output_b <<" Actual output \n";
            cout << max_output_b << " My Output\n";
        }
    }
}
