class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
        int start = lower(nums, target);
        int end = upper(nums, target);
        
        if(start != end){
            ans[0] = start;
            ans[1] = end-1;
        }
        
        return ans;
    }
    
    public int lower(int[] nums, int target){
        int left = 0;
        int right = nums.length;
        
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        
        return right;
    }
    public int upper(int[] nums, int target){
        int left = 0;
        int right = nums.length;
        
        while(left < right){
            int mid = (left + right) / 2;
            
            if(nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        
        return right;
    }
}
