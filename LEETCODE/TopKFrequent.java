class TopKFrequent {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] ans = new int[k];
        for(int num : nums){
            map.put(num, map.getOrDefault(num,0)+1);
        }
        Queue<Integer> pq = new PriorityQueue<>((a,b) -> (map.get(b) - map.get(a)));
        for(int num: map.keySet()){
            pq.add(num);
        }
        
        for(int i=0 ; i<k ; i++){
            ans[i] = pq.poll();
        }
        return ans;
    }
}
