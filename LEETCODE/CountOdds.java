class Solution {
    public int countOdds(int low, int high) {
        int cnt = 0;
        if(low % 2 == 1 || high % 2 == 1){
            cnt++;
        }
        cnt += (high-low)/2;
        return cnt;
    }
}
