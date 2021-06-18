class Solution {
    public boolean detectCapitalUse(String word) {
        boolean flag = false;
        int cnt = 0;
        
        for(int i=0 ; i<word.length() ; i++){
            if(Character.isLowerCase(word.charAt(i))) cnt++;
        }
        if(Character.isUpperCase(word.charAt(0)) && word.length() - cnt == 1) flag = true;
        if(word.length() == cnt || cnt == 0) flag = true;
        return flag;
    }
}
