class Solution {
    public int removeElement(int[] nums, int val) {
        int ans = 0;
        for(int i=0 ; i<nums.length ; i++){
            if(nums[i] == val) nums[i] = -1;
            else ans++;
        }
        for(int i=nums.length-2 ; i>=0 ; i--){
            if(nums[i] != -1) continue;
            
            for(int j=i ; j<nums.length-1 ; j++){
                if(nums[j+1] == -1) break;
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
        
        return ans;
        
    }
}