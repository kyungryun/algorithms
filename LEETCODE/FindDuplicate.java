class FindDuplicate {
    public int findDuplicate(int[] nums) {
        for(int i=0 ; i<nums.length ; i++){
            int temp = nums[Math.abs(nums[i])];
            
            if(temp >= 0){
                nums[Math.abs(nums[i])] *= -1;
            }else{
                return Math.abs(nums[i]);
            }
        }
        
        return nums[0];
    }
}
