class WiggleSort {
    public void wiggleSort(int[] nums) {
        int[] arr = new int[nums.length];
        
        for(int i=0 ; i<nums.length ; i++) arr[i] = nums[i];
        Arrays.sort(arr);
        
        int mid = (nums.length-1) / 2;
        int left = mid;
        int right = nums.length - 1;
        int idx = 0;
        while(left >= 0 && right > mid){
            nums[idx++] = arr[left--];
            nums[idx++] = arr[right--];
        }
        
        while(left >= 0) nums[idx++] = arr[left--];
        while(right > mid) nums[idx++] = arr[right--];
    }
}
