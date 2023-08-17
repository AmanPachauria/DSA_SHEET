class Solution {
public:

    bool isvalid(vector<vector<char>> &board, int row, int col, char ch){
            for( int i = 0; i < 9; i++ ){
                  if(board[i][col]==ch) return false;
            }
            for( int j = 0; j < 9; j++ ){
                if(board[row][j]==ch) return false;
            }

            int a = row/3, b = col/3;
            a = a*3; b = b*3;
            for(int i = a; i < a+3; i++ ){
                for( int j = b; j < b+3; j++){
                    if(board[i][j]==ch) return false;
                }
            }

            return true;
    }
    
    bool sudoku(vector<vector<char>> &board){
        for( int i = 0; i < 9; i++ ){
            for( int j = 0; j < 9; j++ ){
                if(board[i][j]=='.'){
                     for( char ch = '1'; ch <= '9'; ch++){
                           if(isvalid(board, i, j, ch)){
                               board[i][j] = ch;
                               if((sudoku(board))){
                                   return true;
                               }
                               else{
                                   board[i][j] = '.';
                               }
                           }
                     }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
    
       sudoku(board);
        
    }
};