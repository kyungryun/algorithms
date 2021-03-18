class ReverseOnlyLetters {
    public String reverseOnlyLetters(String S) {
        char[] c = S.toCharArray();
        int l=0;
        int r=S.length() - 1;
        
        while(l <= r){
            if(!Character.isLetter(c[l])) l++;
            if(!Character.isLetter(c[r])) r--;
            else if(Character.isLetter(c[l]) && Character.isLetter(c[r])){
                char tmp = c[l];
                c[l] = c[r];
                c[r] = tmp;
                l++;
                r--;
            }
        }
        
        return new String(c);
    }
}
