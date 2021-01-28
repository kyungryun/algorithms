class SortColors {
    public void sortColors(int[] nums) {
        int r = 0;
        int w = 0;
        for(int num : nums){
            if(num == 0) r++;
            else if(num == 1) w++;
        }
        for(int i=0 ; i<nums.length ; i++){
            if(r != 0){
                nums[i] = 0;
                r--;
            }else if(w != 0){
                nums[i] = 1;
                w--;
            }else nums[i] = 2;
        }
    }
}
