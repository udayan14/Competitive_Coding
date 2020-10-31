#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template<typename T, typename U> 
static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
} 
  
// call by reference is used in x 
template<typename T, typename U> 
static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}


const long long int p = 1000000007;

bool isCompatible(int row,int col, const vector<string> &board){
	for(int i=0 ; i<row ; i++){
		if(board[i][col]=='Q') return false;
	}
	int i=1;
	while(row-i >= 0 && col-i >=0){
		if(board[row-i][col-i]=='Q') return false;
		i++;
	}
	i = 1;
	while(row-i >= 0 && col+i <=7){
		if(board[row-i][col+i]=='Q') return false;
		i++;
	}
	return true;
}

int solve_helper(const vector<string> &input, vector<string> &board, int row){
	if(row==7){
		int out = 0;
		for(int col=0 ; col<8 ; col++){
			if(input[row][col]=='.' && isCompatible(row,col,board)) out++;
		}
		return out;
	}
	int out = 0;
	for(int col=0 ; col<8 ; col++){
		if(input[row][col]=='.' && isCompatible(row,col,board)){
			board[row][col] = 'Q';
			out += solve_helper(input,board,row+1);
			board[row][col] = '.';
		}
	}
	return out;
}

int solve(const vector<string> &input){
	vector<string> board(8);
	for(int i=0 ; i<8 ; i++){
		board[i] = "........";
	}
	return solve_helper(input,board,0);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        vector<string> input(8);
		string s;
		for(int i=0 ; i<8 ; i++){
			cin >> s;
			input[i] = s;
		}
		cout << solve(input) << "\n";
    }
    return 0;
}

