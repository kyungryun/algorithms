//import java.util.*;

class BigNumber {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();
        int idx = 0;
        
        for(int i=0 ; i<number.length() - k ; i++){
            int temp = 0;    
            for(int j=idx ; j<=i+k ; j++){
                if(temp < number.charAt(j)-'0'){
                    temp = number.charAt(j)-'0';
                    idx = j + 1;
                }
            }
            sb.append(temp);
        }
        return sb.toString();
    }
}
