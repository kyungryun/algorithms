class LengthOfLongestSubstring {
    public int lengthOfLongestSubstring(String s) {
        boolean[] b = new boolean[256];
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right < s.length()){
            int cur = s.charAt(right);
            while(b[cur]){
                b[s.charAt(left++)] = false;
            }
            
            b[cur] = true;
            ans = Math.max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
}
