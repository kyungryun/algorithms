class ProductExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        ans[0] = 1;
        for(int i=1 ; i<nums.length ; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int back = 1;
        for(int i=nums.length-2 ; i>=0 ; i--){
            back = back*nums[i+1];
            ans[i] = back*ans[i];
        }
        
        return ans;
    }
}
