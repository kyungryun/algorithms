class ExcelColumnNumber {
    public int titleToNumber(String s) {
        int ans = 0;
        for(int i=0 ; i<s.length() ; i++){
            ans += s.charAt(i) - 'A' + 1;
            if(i != s.length() - 1) ans *= 26;
        }
        return ans;
    }
}