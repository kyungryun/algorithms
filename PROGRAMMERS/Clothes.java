import java.util.*;
class Clothes {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> hm = new HashMap<>();
        
        for(int i=0 ; i<clothes.length ; i++){
            hm.put(clothes[i][1], hm.getOrDefault(clothes[i][1], 0) + 1);
        }
        
        Set<String> ks = hm.keySet();
        for(String key : ks){
            answer *= hm.get(key) + 1;
        }
        return answer-1;
    }
}
