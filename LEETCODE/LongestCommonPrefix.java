class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        String minStr = "";
        int len = 987654321;
        
        for(String str : strs){
            if(str.length() < len){
                len = str.length();
                minStr = str;
            }
        }
        
        for(String str : strs){
            while(!str.startsWith(minStr)){
                minStr = minStr.substring(0, len-1);
                len--;
            }
        }
        
        return minStr;
    }
}
