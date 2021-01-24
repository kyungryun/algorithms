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
