class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int ans = 0;
        int size = timeSeries.length;
        int end = -1;
        for(int time : timeSeries){
            ans += duration;
            if(time <= end) ans -= (end - time + 1);
            
            end = time + duration - 1;
        }
        
        return ans;
    }
}
