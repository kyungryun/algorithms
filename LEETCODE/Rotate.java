class Solution {
    public void rotate(int[][] matrix) {
        int l = matrix.length;
        
        for(int i=0 ; i<l ; i++){
            for(int j=i ; j<l-i-1 ; j++){
                int temp = matrix[i][j];
                
                // 왼쪽 아래
                matrix[i][j] = matrix[l-j-1][i];
                // 오른쪽 아래
                matrix[l-j-1][i] = matrix[l-i-1][l-j-1];
                // 오른쪽 위
                matrix[l-i-1][l-j-1] = matrix[j][l-i-1];
                // 왼쪽 위
                matrix[j][l-i-1] = temp;
            }
        }
    }
}
