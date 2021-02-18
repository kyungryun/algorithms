class MaxProduct {
    public int maxProduct(int[] nums) {
        int max = nums[0];
        int min = nums[0];
        int ans = nums[0];
        
        for(int i=1 ; i<nums.length ; i++){
            int minCur = nums[i] * min;
            int maxCur = nums[i] * max;
            max = Math.max(nums[i], Math.max(maxCur, minCur));
            min = Math.min(nums[i], Math.min(maxCur, minCur));
            
            ans = Math.max(ans, max);
        }
        
        return ans;
    }
}
