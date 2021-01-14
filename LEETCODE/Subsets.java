class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        subset(nums, 0, new ArrayList<Integer>(), ans);
        return ans;
    }
    
    void subset(int[] nums, int idx, List<Integer> now, List<List<Integer>> ans){
        ans.add(new ArrayList<>(now));
        
        for(int i=idx ; i<nums.length ; i++){
            now.add(nums[i]);
            subset(nums, i+1, now, ans);
            now.remove(now.size() - 1);
        }
    }
    
}
