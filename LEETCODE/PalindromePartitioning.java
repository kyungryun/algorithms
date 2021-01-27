class PalindromePartitioning {
    public boolean isPalindrome(String str){
        int s = 0;
        int e = str.length() - 1;
        while(s<e){
            if(str.charAt(s++) != str.charAt(e--)) return false;
        }
        return true;
    }
    public void dfs(String str, List<List<String>> ans, List<String> cur){
        if(str.length() == 0){
            ans.add(new ArrayList<>(cur));
            return;
        }
        for(int i=0 ; i<str.length() ; i++){
            String curString = str.substring(0, i+1);
            if(isPalindrome(curString)){
                cur.add(curString);
                dfs(str.substring(i+1), ans, cur);
                cur.remove(cur.size() - 1);    
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        dfs(s, ans, new ArrayList<String>());
        return ans;
    }
}
