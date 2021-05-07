import java.util.*;
class ReverseArray {
    public int[] solution(long n) {
        int[] answer;
        Queue<Long> q = new LinkedList<>();
        while(n > 0){
            q.offer(n%10);
            n /= 10;
        }
        answer = new int[q.size()];
        int idx = 0;
        for(Long num : q){
            answer[idx++] = num.intValue();
        }
        return answer;
    }
}
