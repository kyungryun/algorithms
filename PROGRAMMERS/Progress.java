import java.util.*;
class Progress {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> q = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        for(int i=0 ; i<progresses.length ; i++){
            q.offer((100-progresses[i]) % speeds[i] == 0 ? 
                    (100-progresses[i])/speeds[i] : (100-progresses[i])/speeds[i] + 1);
        }
        int prev = q.poll();
        int cnt = 1;
        while(!q.isEmpty()){
            int now = q.poll();
            if(prev >= now) cnt++;
            else{
                list.add(cnt);
                cnt = 1;
                prev = now;
            }
        }
        list.add(cnt);
        
        int[] answer = new int[list.size()];
        
        for(int i=0 ; i<answer.length ; i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}
