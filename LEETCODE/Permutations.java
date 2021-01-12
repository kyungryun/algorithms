class Permutations {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        perm(nums, ans, curr, visited);
        return ans;
    }
    
    public void perm(int[] nums, List<List<Integer>> ans, List<Integer> curr, boolean[] visited){
        if(curr.size() == nums.length){
            ans.add(new ArrayList(curr));
            return;
        }
        
        for(int i=0 ; i<nums.length ; i++){
            if(!visited[i]){
                visited[i] = true;
                curr.add(nums[i]);
                perm(nums, ans, curr, visited);
                curr.remove(curr.size()-1);
                visited[i] = false;
            }
        }
    }
}
