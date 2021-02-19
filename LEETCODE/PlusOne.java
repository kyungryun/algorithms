class PlusOne {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int[] carry = new int[len+1];
        carry[0] = 0;
        
        for(int i=0 ; i<len ; i++){
            carry[i+1] = digits[i];
        }
        
        carry[len]++;
        while(carry[len] > 9){
            carry[len] = carry[len]%10;
            len--;
            carry[len]++;
        }
        
        
        if(carry[0] == 0){
            for(int i=0 ; i<digits.length ; i++){
                digits[i] = carry[i+1];
            }
            return digits;
        }
        
        return carry;
    }
}
