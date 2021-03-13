class FindKthLargest {
    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> queue = new PriorityQueue<Integer>();
        for(int i=0 ; i<k ; i++){
            queue.add(nums[i]);
        }
        for(int i=k ; i<nums.length ; i++){
            if(nums[i] > queue.peek()){
                queue.poll();
                queue.add(nums[i]);
            }
        }
        
        return queue.peek();
    }
}
