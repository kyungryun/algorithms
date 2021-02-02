class MyAtoi {
    public int myAtoi(String s) {
        int len = s.length();
        int idx = 0;
        int flag = 1;    
        while(idx < len && s.charAt(idx) == ' ') idx++;
        
    
        if(idx < len){
            char sign = s.charAt(idx);
            if(sign == '-'){
                flag = -1;
                idx++;
            }else if(sign == '+'){
                idx++;
            }    
        }
        
        
        char[] buf = new char[len];
        int bufIdx = 0;
        while(idx < len && Character.isDigit(s.charAt(idx))){
            buf[bufIdx++] = s.charAt(idx++);
        }
        if(bufIdx < 1) return 0;
        
        long ans = 0;
        
        for(int i=0 ; i<bufIdx ; i++){
            ans = ans*10 + (buf[i]-'0');
            if(ans > Integer.MAX_VALUE){
                return flag == 1 ? Integer.MAX_VALUE : -Integer.MIN_VALUE;
            }
        }
           
        return (int)ans*flag;
    }
}
