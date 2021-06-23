class Solution {
    public int lengthOfLastWord(String s) {
        if(s == null || s.length() == 0) return 0;
        int ans = 0;
        boolean flag = false;
        for(int i=s.length()-1 ; i>=0 ; i--){
            char c = s.charAt(i);
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                flag = true;
                ans++;
            }else if(flag) return ans;
        }
        
        return ans;
    }
}
