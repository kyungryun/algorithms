class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        
        Arrays.sort(intervals, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                return o1[0] - o2[0];
            }
        });
        
        for(int i=0 ; i<intervals.length-1 ; i++){
            if(intervals[i][1] >= intervals[i+1][0]){
                intervals[i+1][0] = Math.min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = Math.max(intervals[i][1], intervals[i+1][1]);
            }else{
                ans.add(intervals[i]);
            }
        }
        ans.add(intervals[intervals.length-1]);
        
        return ans.toArray(new int[ans.size()][]);
    }
}
