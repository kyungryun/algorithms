class FractionToDecimal {
    public String fractionToDecimal(int numerator, int denominator) {
        String ans = "";
        
        if(numerator < 0 && denominator > 0){
            ans += "-";
        }else if(numerator > 0 && denominator < 0){
            ans += "-";
        }
        
        long n = Math.abs(Long.valueOf(numerator));
        long d = Math.abs(Long.valueOf(denominator));
        
        long div = n/d;
        ans += String.valueOf(div);
        
        long reminder = (n%d) * 10;
        if(reminder == 0) return ans;
        
        HashMap<Long, Integer> m = new HashMap<>();
        ans += ".";
        while(reminder != 0){
            if(m.containsKey(reminder)){
                int decimal = m.get(reminder);
                return ans.substring(0, decimal) + "(" + ans.substring(decimal, ans.length()) + ")";
            }
            m.put(reminder, ans.length());
            div = reminder / d;
            ans += String.valueOf(div);
            reminder = (reminder%d) * 10;
            
        }
        
        return ans;
    }
}
