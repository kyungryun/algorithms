import java.util.*;
class BracketRotate {
    public boolean check(String s){
        Stack<Character> st = new Stack<>();
        
        for(int i=0 ; i<s.length() ; i++){
            char c = s.charAt(i);
            if(c == '[' || c == '{' || c == '(') st.push(c);
            else if(!st.isEmpty()){
                if(st.peek() == '[' && c == ']') st.pop();
                else if(st.peek() == '{' && c == '}') st.pop();
                else if(st.peek() == '(' && c == ')') st.pop();
            }else return false;
        }
        return st.isEmpty();
    }
    public int solution(String s) {
        int answer = 0;
        StringBuffer str = new StringBuffer(s);
        for(int i=0 ; i<str.length()-1 ; i++){
            if(check(str.toString())) answer++;
            char c = str.charAt(0);
            str.deleteCharAt(0);
            str.append(c);
            
        }
        return answer;
    }
}
