class FloodFill {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,image[sr][sc], newColor);
        return image;
    }
    
    public void dfs(int[][] image, int r, int c, int ori, int target){
        if(r < 0 || c < 0 || r >= image.length || c >= image[0].length || image[r][c] == target) return;
        
        if(image[r][c] == ori){
            image[r][c] = target;
            
            dfs(image, r+1, c, ori, target);
            dfs(image, r-1, c, ori, target);
            dfs(image, r, c+1, ori, target);
            dfs(image, r, c-1, ori, target);
        }
    }
}
