class DecodeWays {
    public int numDecodings(String s) {
        int[] dp = new int[s.length()+1];
        dp[0] = 1;
        if(s.charAt(0) == '0') dp[1] = 0;
        else dp[1] = 1;
        
        for(int i=2 ; i<dp.length ; i++){
            if(s.charAt(i-1) - '0' != 0){
                dp[i] += dp[i-1];
            }
            int two = Integer.valueOf(s.substring(i-2, i));
            if(two >= 10 && two <= 26){
                dp[i] += dp[i-2];
            }
            
        }
        
        return dp[s.length()];
    }
}
