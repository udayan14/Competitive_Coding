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
 
void solve_helper(const string &s, vector<vector<short>> &board, int &ans, int index, int row, int col){
	//cout << index << " " << row << " " << col << "\n";
	if(row==6 && col==0){
		if(index==48) ++ans;
		return;
	}
 
	if(s[index]=='?'){
		if(row+1<7 && board[row+1][col]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && row+1==6 && col+1<7 && board[row+1][col+1]==0){

			}
			else{
				board[row+1][col] = 1;
				solve_helper(s,board,ans,index+1,row+1,col);
				board[row+1][col] = 0;
			}
		}
		if(row-1 >-1 && board[row-1][col]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && row-1==0 && col-1>-1 && board[row-1][col-1]==0){
			}
			else{
				board[row-1][col] = 1;
				solve_helper(s,board,ans,index+1,row-1,col);
				board[row-1][col] = 0;
			}
		}
		if(col-1 > -1 && board[row][col-1]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && col-1==0 && row-1 > -1 && board[row-1][col-1]==0){
			}
			else{
				board[row][col-1] = 1;
				solve_helper(s,board,ans,index+1,row,col-1);
				board[row][col-1] = 0;
			}
		}
		if(col+1 < 7 && board[row][col+1]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && col+1==6 && row-1>-1 && board[row-1][col+1]==0){
			}
			else{
				board[row][col+1] = 1;
				solve_helper(s,board,ans,index+1,row,col+1);
				board[row][col+1] = 0;
			}
		}
	}
 
	else if(s[index]=='D'){
		if(row+1<7 && board[row+1][col]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && row+1==6 && col+1<7 && board[row+1][col+1]==0){
				return;
			}	
			board[row+1][col] = 1;
			solve_helper(s,board,ans,index+1,row+1,col);
			board[row+1][col] = 0;
		}
	}
 
	else if(s[index]=='U'){
		if(row-1 >-1 && board[row-1][col]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6  && row-1==0 && col-1>-1 && board[row-1][col-1]==0){
				return;
			}
			board[row-1][col] = 1;
			solve_helper(s,board,ans,index+1,row-1,col);
			board[row-1][col] = 0;
		}
	}
 
	else if(s[index]=='L'){
		if(col-1 > -1 && board[row][col-1]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && col-1==0 && row-1>-1 && board[row-1][col-1]==0){
				return;
			}
			board[row][col-1] = 1;
			solve_helper(s,board,ans,index+1,row,col-1);
			board[row][col-1] = 0;
		}
	}
 
	else if(s[index]=='R'){
		if(col+1 < 7 && board[row][col+1]==0){
			if(row > 0 && row < 6 && col > 0 && col < 6 && col+1==6 && row-1>-1 && board[row-1][col+1]==0){
				return;
			}
			board[row][col+1] = 1;
			solve_helper(s,board,ans,index+1,row,col+1);
			board[row][col+1] = 0;
		}
	}
	return;
}
 
int solve(const string &s){
	vector<vector<short>> board(7,vector<short>(7,0));
	board[0][0] = 1;
	int index = 0;
	int row = 0;
	int col = 0;
	int out = 0;
	if(s[0]=='?' && s[1]=='?' && s[2]=='?'){
		board[0][1] = 1;
		index++;
		board[0][2] = 1;
		index++;
		solve_helper(s,board,out,index,row,col+2);
		board[0][2] = 0;
		board[1][1] = 1;
		board[1][0] = 1;
		solve_helper(s,board,out,index+1,row+1,col);
		solve_helper(s,board,out,index+1,row,col+1);
		board[0][1] = 0;
		board[1][1] = 0;
		board[2][0] = 1;
		solve_helper(s,board,out,index,row+2,col);
		return out;
	}
	solve_helper(s,board,out,index,row,col);
	return out;
}
 
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
	t = 1;
 
    while(t--){
        string s;
		cin >> s;
		cout << solve(s) << "\n";
    }
    return 0;
}
 
