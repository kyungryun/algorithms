class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        int[] dr = new int[]{0, 1, 0, -1};
        int[] dc = new int[]{1, 0, -1, 0};
        int nDir = 0;
        int r = 0;
        int c = 0;
        int n = matrix.length;
        int m = matrix[0].length;
        boolean[][] visited = new boolean[n][m];
        
        List<Integer> ans = new ArrayList<>();
        while(!visited[r][c]){
            visited[r][c] = true;
            ans.add(matrix[r][c]);
            
            for(int i=0 ; i<4 ; i++){
                nDir = (nDir + i) % 4;
                
                int nr = r + dr[nDir];
                int nc = c + dc[nDir];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]){
                    r = nr;
                    c = nc;
                    break;
                }
            }
        }
                
        return ans;
    }
}
