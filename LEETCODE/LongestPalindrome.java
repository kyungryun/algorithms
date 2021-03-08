class LongestPalindrome {
    public String longestPalindrome(String s) {
        int len = s.length();
        if(len == 1) return s;
        String ans = "";
        String str = "";
        char[] arr = s.toCharArray();
        
        for(int i=0 ; i<len-1 ; i++){
            int left = i;
            int right = i+1;
            str = "";
            while(left >= 0 && right < len && arr[left] == arr[right]){
                str = arr[left] + str + arr[right];
                left--;
                right++;
            }
            if(ans.length() < str.length()) ans = str;
            
            str = arr[i] + "";
            left = i-1;
            right = i+1;
            
            while(left >= 0 && right < len && arr[left] == arr[right]){
                str = arr[left] + str + arr[right];
                left--;
                right++;
            }
            if(ans.length() < str.length()) ans = str;
        }
        
        return ans;
    }
}
