import java.util.*;

class Bridge_Truck {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        int sum = 0;
        
        for(int truck : truck_weights){
            while(true){
                if(q.isEmpty()){
                    q.add(truck);
                    sum += truck;
                    answer++;
                    break;
                }else if(q.size() == bridge_length){
                    sum -= q.poll();
                }else{
                    if(truck + sum > weight){
                        q.add(0);
                        answer++;
                    }else{
                        q.add(truck);
                        sum += truck;
                        answer++;
                        break;
                    }
                }
            }
        }
        
        return answer + bridge_length;
    }
}
