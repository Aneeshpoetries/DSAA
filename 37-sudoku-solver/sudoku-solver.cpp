class Solution {
public:

    bool isValid(vector<vector<char>>& board, int r, int c, char num){
        for(int i=0;i<9;i++){
            if(board[r][i]==num) return false;
            if(board[i][c]==num) return false;

            int boxRow = 3*(r/3) + i/3;
            int boxCol = 3*(c/3) + i%3;

            if(board[boxRow][boxCol]==num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9'; c++){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;

                            if(solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};