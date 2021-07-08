class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();
        
        while(columnNumber > 0){
            if(columnNumber%26 == 0){
                sb.append("Z");
                columnNumber/=26;
                columnNumber--;
            }else{
                int d = columnNumber%26;
                String s = String.valueOf((char)(64+d));
                sb.append(s);
                columnNumber/=26;
            }
        }
        
        return sb.reverse().toString();
    }
}
