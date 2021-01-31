class NumIslands {
    public int[] dr = new int[] {1, 0, -1, 0};
    public int[] dc = new int[] {0, 1, 0, -1};
    public void dfs(char[][] grid, boolean[][] visited, int r, int c){
        visited[r][c] = true;
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= grid.length || nc < 0 || nc >= grid[0].length || visited[nr][nc]) continue;
            if(grid[nr][nc] == '1') dfs(grid, visited, nr, nc);
        }
    }
    public int numIslands(char[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int ans = 0;
        for(int i=0 ; i<grid.length ; i++){
            for(int j=0 ; j<grid[0].length ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
}
