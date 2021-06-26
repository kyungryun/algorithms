class Solution {
    public String countAndSay(int n) {
        if(n == 1) return "1";
        
        StringBuilder sb = new StringBuilder();
        String str = countAndSay(n-1);
        int count = 1;
        
        for(int i = 1 ; i < str.length() ; i++){
            char c = str.charAt(i);
            
            if(str.charAt(i) != str.charAt(i-1)){
                sb.append(Integer.toString(count)).append(str.charAt(i-1));
                count = 1;
            }else{
                count++;
            }
            
        }
        
        sb.append(Integer.toString(count)).append(str.charAt(str.length()-1));
        
        return sb.toString();
    }
}
