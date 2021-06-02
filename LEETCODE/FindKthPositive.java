class Solution {
    public int findKthPositive(int[] arr, int k) {
        /*       
        int num = 0;
        int last = arr[arr.length-1];
        List<Integer> resList = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        for(int i=0 ; i<arr.length ; i++) list.add(arr[i]);
        
        for(int i=0 ; i<last ; i++){
            if(!list.contains(i)) resList.add(i);
        }
        for(int i=0 ; i<resList.size() ; i++){
            if(i == k){
                num = resList.get(i);
                break;
            }
        }
        return num == 0 ? arr.length + k : num;
        */
        int ans = 0;
        int idx = 0;
        while(k > 0){
            ans++;
            if(idx < arr.length && ans == arr[idx]) idx++;
            else k--;
        }
        return ans;
        
    }
}
