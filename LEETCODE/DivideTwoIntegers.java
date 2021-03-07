class DivideTwoIntegers {
    public int divide(int dividend, int divisor) {
        if(dividend == 1<<31 && divisor == -1) return Integer.MAX_VALUE;
        boolean flag = true;
        
        
        if((dividend < 0) ^ (divisor < 0)){
            flag = false;
        }
        
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        
        int ans = 0;
        
        while(dividend - divisor >= 0){
            int shift = 0;
            
            while(dividend - (divisor<<1<<shift) >= 0) shift++;
            
            ans += 1 << shift;
            dividend -= (divisor<<shift);
        }
        
        return flag ? ans : -ans;
    }
}
