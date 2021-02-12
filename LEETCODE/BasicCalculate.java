class Calculate {
    public int calculate(String s) {
        int ans = 0;
        int cur = 0;
        int calc = 0;
        int oper = '+';
        for(int i=0 ; i<s.length() ; i++){
            
            char c = s.charAt(i);
            if(c == ' ' && i != s.length()-1) continue;
            if(Character.isDigit(c)){
                cur = cur*10 + (c-'0');
            }
            if(!Character.isDigit(c) || i == s.length()-1){
                if(oper == '+'){
                    ans += calc;
                    calc = cur;
                }else if(oper == '-'){
                    ans += calc;
                    calc = -cur;
                }else if(oper == '*'){
                    calc *= cur;
                }else if(oper == '/'){
                    calc /= cur;
                }
                cur = 0;
                oper = c;    
            }
            
        }
        
        return ans + calc;
    }
}
