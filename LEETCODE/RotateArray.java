class RotateArray {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        step(nums, 0, nums.length-1);
        step(nums, 0, k-1);
        step(nums, k, nums.length-1);
        
    }
    public void step(int[] nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
}
