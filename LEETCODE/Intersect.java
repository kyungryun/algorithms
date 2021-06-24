class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> list = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i=0 ; i<nums1.length ; i++){
            if(map.containsKey(nums1[i])){
                map.put(nums1[i], map.get(nums1[i])+1);
            }else map.put(nums1[i], 1);
        }
        
        for(int i=0 ; i<nums2.length ; i++){
            if(map.containsKey(nums2[i]) && map.get(nums2[i]) >= 1){
                list.add(nums2[i]);
                map.put(nums2[i], map.get(nums2[i])-1);
            }
        }
        
        int ans[] = new int[list.size()];
        int i=0;
        for(Integer n : list){
            ans[i++] = n;
        }
        
        return ans;
    }
}
