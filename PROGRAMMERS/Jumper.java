import java.util.*;

public class Jumper {
    public int solution(int n) {
        int cnt = 1;
        int answer = 0;
        while(n != 0){
            if(n % 2 == 1){
                n -= cnt;
                ans += 1;
            }
            n /= 2;
        }
        return answer;
        //return Integer.bitCount(n);
    }
}
