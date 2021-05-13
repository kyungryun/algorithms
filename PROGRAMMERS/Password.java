import java.util.*;
class Password {
    public String solution(String s, int n) {
        StringBuilder sb = new StringBuilder();
        for(int i=0 ; i<s.length() ; i++){
            char c;
            if(s.charAt(i) == ' '){
                c = ' ';
            }
            else if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z'){
                c = (char)((s.charAt(i) - 'a' + n)%26 + 'a');
            }else{
                c = (char)((s.charAt(i) - 'A' + n)%26 + 'A');
            }
            sb.append(c);
        }
        return sb.toString();
    }
}
