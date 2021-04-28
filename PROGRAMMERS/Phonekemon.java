import java.util.*;
class Phonekemon {
    public int solution(int[] nums) {
        int answer = nums.length / 2;
        Set<Integer> hs = new HashSet<>();
        
        for(int num : nums) hs.add(num);
        
        if(hs.size() < answer) return hs.size();
        else return answer;
    }
}
