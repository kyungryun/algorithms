class StrangeString {
    public String solution(String s) {
        String[] strings = s.split(" ", -1);
        StringBuilder sb = new StringBuilder();
        for(String str : strings){
            for(int i=0 ; i<str.length() ; i++){
                if(i%2 == 0) sb.append(Character.toUpperCase(str.charAt(i)));
                else sb.append(Character.toLowerCase(str.charAt(i)));
            }
            sb.append(" ");
        }
        return sb.substring(0, sb.length()-1);
    }
}
