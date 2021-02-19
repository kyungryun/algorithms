class LIS {
    public int lengthOfLIS(int[] nums) {
        int[] arr = new int[nums.length];
        
        int ans = 0;
        
        for(int i=0 ; i<nums.length ; i++){
            int left = 0;
            int right = ans;
            
            while(left < right){
                int mid = (left + right) / 2;
                
                if(arr[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            
            arr[left] = nums[i];
            if(left == ans) ans++;
        }
        return ans;
    }
}
