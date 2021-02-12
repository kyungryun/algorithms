class IsValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] != '.' && !isValid(board,i,j)) return false;
            }
        }
        
        return true;
    }
    
    public boolean isValid(char[][] board, int r, int c){
        
        for(int i=0 ; i<9 ; i++){
            if(i != r && board[r][c] == board[i][c]) return false;
            if(i != c && board[r][c] == board[r][i]) return false;
        }
        
        int sr = r/3 * 3;
        int sc = c/3 * 3;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                if((sr + i != r && sc + j != c) && board[sr+i][sc+j] == board[r][c]) return false;
            }
        }
        
        return true;
    }
}
