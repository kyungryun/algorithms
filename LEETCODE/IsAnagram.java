class IsAnagram {
    public boolean isAnagram(String s, String t) {
        int[] sArr = new int[26];
        int[] tArr = new int[26];
        
        if(s.length() != t.length()) return false;
        
        for(int i=0; i<s.length(); i++) sArr[s.charAt(i)-'a']++;
        for(int i=0; i<t.length(); i++) tArr[t.charAt(i)-'a']++;
        
        for(int i=0 ; i<26 ; i++){
            if(sArr[i] != tArr[i]) return false;
        }
        return true;
    }
}
