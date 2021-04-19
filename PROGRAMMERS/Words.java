import java.util.*;
class Words {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[]{0,0};
        List<String> list = new ArrayList<>();
        for(int i=0 ; i<words.length ; i++){
            if(list.contains(words[i])){
                answer[0] = (i%n) + 1;
                answer[1] = (i/n) + 1;
                break;
            }
            list.add(words[i]);
            if(i > 0 && words[i-1].charAt(words[i-1].length() - 1) != words[i].charAt(0)){
                answer[0] = (i%n) + 1;
                answer[1] = (i/n) + 1;
                break;
            }
        }
        return answer;
    }
}