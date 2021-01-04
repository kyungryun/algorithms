class HouseRobber {
    public int rob(int[] nums) {
        if(nums.length == 1) return nums[0];

        int ans = 0;
        int now = 0;
        for(int num : nums){
            int temp = now;
            now = ans;
            ans = Math.max(ans, num + temp);
        }

        return ans;
    }
}