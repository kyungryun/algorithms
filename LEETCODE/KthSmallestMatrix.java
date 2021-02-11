class KthSmallestMatrix {
    public int kthSmallest(int[][] matrix, int k) {
        Queue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i=0 ; i<matrix.length ; i++){
            for(int j=0 ; j<matrix[0].length ; j++){
                pq.add(matrix[i][j]);
                if(pq.size() > k) pq.poll();
            }
        }
        return pq.peek();
    }
}

class KthSmallestMatrix_BS {
    public int kthSmallest(int[][] matrix, int k) {
        int left = matrix[0][0];
        int right = matrix[matrix.length-1][matrix.length-1];
        
        while(left <= right){
            int mid = (left + right) / 2;
            int cnt = 0;
            
            for(int i=0; i<matrix.length ; i++){
                for(int j=0 ; j<matrix[i].length ; j++){
                    if(matrix[i][0] > mid) break;
                    if(matrix[i][j] <= mid) cnt++;
                }
            }
            
            if(cnt < k) left = mid + 1;
            else right = mid - 1;
        }
        
        return left;
    }
}
