class LetterCombinations {
    String[] letters = new String[]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public void dfs(int idx, String str, String digits, List<String> ans){
        if(idx == digits.length()){
            ans.add(str);
            return;
        }
        int digit = digits.charAt(idx) - '0';
        for(char c : letters[digit].toCharArray()){
            str += Character.toString(c);
            dfs(idx+1, str, digits, ans);
            str = str.substring(0, str.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if(digits.length() == 0) return ans;
        
        dfs(0, "", digits, ans);
        
        return ans;
    }
}
