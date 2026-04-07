class Solution {
public:
    void solve(vector<vector<string>>&ans,vector<string>&board, vector<int>left, vector<int>up, vector<int>down, int n, int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
                if(left[i]==0&&down[i+col]==0&&up[n-1+col-i]==0){
                    board[i][col]='Q';
                    left[i]=1;
                    down[i+col]=1;
                    up[n-1+col-i]=1;
                    solve(ans,board,left,up,down,n,col+1);
                    board[i][col]='.';
                    left[i]=0;
                    down[i+col]=0;
                    up[n-1+col-i]=0;
                }
            }
            
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>left(n,0);
        vector<int>up(2*n-1,0);
        vector<int>down(2*n-1,0);
        solve(ans,board,left,up,down,n,0);
        return ans;
    }
};