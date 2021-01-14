import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Permutations {
//    public List<List<Integer>> permute(int[] nums) {
//        List<List<Integer>> ans = new ArrayList<>();
//        Stack<Integer> curr = new Stack<>();
//
//        boolean[] visited = new boolean[nums.length];
//        perm(nums, ans, curr, visited);
//        return ans;
//    }
//
//    public void perm(int[] nums, List<List<Integer>> ans, Stack<Integer> curr, boolean[] visited){
//        if(curr.size() == nums.length){
//            ans.add(new ArrayList(curr));
//            return;
//        }
//
//        for(int i=0 ; i<nums.length ; i++){
//            if(!visited[i]){
//                visited[i] = true;
//                curr.push(nums[i]);
//                perm(nums, ans, curr, visited);
//                curr.pop();
//                visited[i] = false;
//            }
//        }
//    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        perm(nums, 0, ans);
        return ans;
    }
    public void perm(int[] nums, int idx, List<List<Integer>> ans){
        if(idx == nums.length){
            List<Integer> temp = new ArrayList<Integer>();
            for(int i=0 ; i<nums.length ; i++) temp.add(nums[i]);
            ans.add(temp);
        }else{
            for(int i=idx ; i<nums.length ; i++){
                swap(nums, idx, i);
                perm(nums, idx+1, ans);
                swap(nums, idx, i);
            }
        }
    }
    public void swap(int nums[], int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
