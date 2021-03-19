class CanConstruct {
    public boolean canConstruct(String ransomNote, String magazine) {
        int []num = new int[26];
        for(int i=0 ; i<magazine.length() ; i++){
            num[magazine.charAt(i)-'a']++;
        }
        
        for(int i=0 ; i<ransomNote.length() ; i++){
            if(num[ransomNote.charAt(i)-'a'] == 0) return false;
            
            num[ransomNote.charAt(i)-'a']--;
        }
        return true;
    }
}
