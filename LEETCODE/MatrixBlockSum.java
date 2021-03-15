class MatrixBlockSum {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] ans = new int[n][m];
        int[][] sum = new int[n+1][m+1];
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                sum[i+1][j+1] = mat[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans[i][j] = sum[Math.min(n, i+K+1)][Math.min(m, j+K+1)]
                        - sum[Math.max(0, i-K)][Math.min(m, j+K+1)]
                        - sum[Math.min(n, i+K+1)][Math.max(0, j-K)]
                        + sum[Math.max(0, i-K)][Math.max(0, j-K)];
            }
        }
        return ans;
    }
}
