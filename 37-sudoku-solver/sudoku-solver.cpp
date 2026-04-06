class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<vector<int>>&col, vector<vector<int>>&row, vector<vector<int>>&box ){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        int b=(i/3)*3+j/3;
                        if(col[j][k]==1 || row[i][k]==1|| box[b][k]==1){
                            continue;
                        }
                        board[i][j]=k+'0';
                        col[j][k]=1;
                        row[i][k]=1;
                        box[b][k]=1;
                        if(solve(board,col,row,box)){
                        return true;
                        }
                        board[i][j]='.';
                        col[j][k]=0;
                        row[i][k]=0;
                        box[b][k]=0;
                    
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
    vector<vector<int>>col(9, vector<int>(10,0));
    vector<vector<int>>row(9, vector<int>(10,0));
    vector<vector<int>>box(9, vector<int>(10,0));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int num=board[i][j]-'0'; 
                int b=(i/3)*3+(j/3);
                col[j][num]=1;
                row[i][num]=1;
                box[b][num]= 1;

            }
        }
    }
    solve(board,col,row,box);

    }
};