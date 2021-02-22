class LongestSubstring {
    public int longestSubstring(String s, int k) {
        return kSubstring(s, k);
    }
    public int kSubstring(String s, int k){
        if(s.length() < k) return 0;
        
         int[] arr = new int[26];
        
        for(int i=0 ; i<s.length() ; i++) arr[s.charAt(i) - 'a']++;
        
        for(int i=0 ; i<s.length() ; i++){
            if(arr[s.charAt(i) - 'a'] >= k) continue;
            int cnt = i+1;
            while(cnt < s.length() && arr[s.charAt(cnt)-'a'] < k)cnt++;
        
            return Math.max(kSubstring(s.substring(0, i),k), kSubstring(s.substring(cnt),k));
        }
        
        return s.length();
    }
}
