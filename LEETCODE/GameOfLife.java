class GameOfLife {
    
    public int solve(int[][] board, int r, int c, int rLen, int cLen){
        int cnt = 0;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        for(int i=0 ; i<8 ; i++){
            int nR = r + dirs[i][0];
            int nC = c + dirs[i][1];
            if(nR >= 0 && nR < rLen && nC >= 0 && nC < cLen && board[nR][nC] == 1){
                cnt++;
            }
        }
        
        return cnt;
    }
    public void gameOfLife(int[][] board) {
        int rLen = board.length;
        int cLen = board[0].length;
        int[][] temp = new int[rLen][cLen];
        
        for(int i=0 ; i<rLen ; i++){
            for(int j=0 ; j<cLen ; j++){
                temp[i][j] = board[i][j];
            }
        }
        
        for(int i=0 ; i<rLen ; i++){
            for(int j=0 ; j<cLen ; j++){
                int cnt = solve(temp, i, j, rLen, cLen);
                if(temp[i][j] == 0){
                    if(cnt == 3){
                        board[i][j] = 1;
                    }
                }else{
                    if(cnt < 2 || cnt > 3){
                        board[i][j] = 0;
                    }else{
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
}
