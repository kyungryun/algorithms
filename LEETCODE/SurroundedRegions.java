class SurroundedRegions {
    int[] dr = {0, 0, 1, -1};
    int[] dc = {1, -1, 0, 0};
    
    public void solve(char[][] board) {
        if(board.length == 0 || board[0].length == 0) return;
        
        int row = board.length;
        int col = board[0].length;
        
        for(int i=0 ; i<row ; i++){
            bfs(board, i, 0);
            bfs(board, i, col-1);
        }
        for(int i=0 ; i<col ; i++){
            bfs(board, 0, i);
            bfs(board, row-1, i);
        }
        
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(board[i][j] == '.') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
    
    public void bfs(char[][] board, int r, int c){
        if(board[r][c] != 'O') return;
        
        int row = board.length;
        int col = board[0].length;
        
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(r, c));
        board[r][c] = '.';
        while(!q.isEmpty()){
            Pair<Integer, Integer> cur = q.poll();
            
            for(int i=0 ; i<4 ; i++){
                int nr = cur.getKey() + dr[i];
                int nc = cur.getValue() + dc[i];
                
                if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if(board[nr][nc] == 'O'){
                    board[nr][nc] = '.';
                    q.add(new Pair<>(nr, nc));    
                }
                
            }
        }
    }
}
