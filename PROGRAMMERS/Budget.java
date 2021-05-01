import java.util.*;
class Budget {
    public int solution(int[] d, int budget) {
        int answer = 0;
        int sum = 0;
        Arrays.sort(d);
        
        for(int dept : d){
            if(dept + sum > budget) break;
            answer++;
            sum += dept;
        }
        return answer;
    }
}
