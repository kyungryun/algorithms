class Solution {
    public int[] runningSum(int[] nums) {
        int[] ans = new int[nums.length];
        int prev = 0;
        
        for(int i=0 ; i<nums.length ; i++){
            ans[i] = prev + nums[i];
            prev = ans[i];
        }
        return ans;
    }
}
