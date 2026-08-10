class Solution {
public:
    bool issafe(vector<vector<char>> &board,int row,int col,char dig){
        for(int j = 0;j<9;j++){
            if(board[row][j] == dig){
                return false;
            }
        }
        for(int i = 0;i<9;i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i = srow;i<=srow+2;i++){
            for(int j = scol;j<=scol+2;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board,int row,int col){
        if(row == 9){
            return true;
        }
        int nextrow = row;
        int nextcol = col+1;
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        if(board[row][col] != '.'){
            return helper(board,nextrow,nextcol);
        }
        for(char dig = '1';dig<='9';dig++){
            if(issafe(board,row,col,dig)){
                board[row][col] = dig;
                if(helper(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};