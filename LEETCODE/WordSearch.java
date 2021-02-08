class WordSearch {
    int[] dr = {1,-1,0,0};
    int[] dc = {0,0,1,-1};
    int[][] visited;
    public boolean dfs(char[][] board, int r, int c, int len, String word){
        if(len == word.length()) return true;
        visited[r][c] = 1;
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nr >= board.length || nc < 0 || nc >= board[0].length || visited[nr][nc] == 1 || board[nr][nc] != word.charAt(len)) continue;
            
            if(dfs(board, nr, nc, len+1, word)) return true;   
        }
        visited[r][c] = 0;
        
        return false;
    }
    public boolean exist(char[][] board, String word) {
        visited = new int[board.length][board[0].length];
        
        for(int i=0 ; i<board.length ; i++){
            for(int j=0 ; j<board[0].length ; j++){
                if(board[i][j] != word.charAt(0)) continue;
                if(dfs(board, i, j, 1, word)) return true;
            }
        }
        
        return false;
    }
}
