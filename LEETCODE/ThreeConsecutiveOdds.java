class ThreeConsecutiveOdds {
    public boolean threeConsecutiveOdds(int[] arr) {
        int cnt = 0;
        boolean flag = false;
        for(int n : arr){
            if(n%2 == 1) cnt++;
            else cnt = 0;
            if(cnt >= 3) return true;
        }
        
        return false;
    }
}
