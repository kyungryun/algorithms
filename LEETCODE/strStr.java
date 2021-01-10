class strStr {
    public int strStr(String haystack, String needle) {
        
        int end = needle.length()-1;
        int start = 0;
        for( ; start <= haystack.length() - needle.length() && end < haystack.length() ; start++){
            if(haystack.substring(start, end+1).equals(needle)){
                return start;
            }
            end++;
        }
        return -1;
    }
}
