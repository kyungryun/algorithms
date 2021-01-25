class FourSumCount {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> m = new HashMap<>();
        int ans = 0;
        for(int a : A){
            for(int b : B){
                int sum = a + b;
                m.put(sum, m.getOrDefault(sum, 0) + 1);
            }
        }
        
        for(int c : C){
            for(int d : D){
                int sum = c + d;
                ans += m.getOrDefault(-sum, 0);
            }
        }
        
        return ans;
    }
}
