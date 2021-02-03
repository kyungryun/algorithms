class WordBreak {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;
        for(int i=0 ; i<=s.length() ; i++){
            for(int j=0 ; j<i ; j++){
                String cur = s.substring(j, i);
                if(dp[j] && wordDict.contains(cur)){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
}
