Brute Force Approach

class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n){
        int r = row;
        int c = col;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        row = r;
        col = c;

        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }

        row = r;
        col = c;

        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string> board, int n, int col){
        if(col == n){
            ans.push_back(board);
            return ;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n , '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        solve(ans, board, n, 0);
        return ans;
    }
};


Optimal Approach

