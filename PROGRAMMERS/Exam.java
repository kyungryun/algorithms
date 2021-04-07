import java.util.*;
class Exam {
    public int[] solution(int[] answers) {
        int[] one = {1,2,3,4,5};
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};
        int[] answer = {};
        int[] score = new int[3];
        for(int i=0 ; i<answers.length ; i++){
            if(one[i%one.length] == answers[i]) score[0]++;
            if(two[i%two.length] == answers[i]) score[1]++;
            if(three[i%three.length] == answers[i]) score[2]++;
        }
        
        int max = Math.max(Math.max(score[0],score[1]), score[2]);
        List<Integer> list = new ArrayList<>();
        for(int i=0 ; i<3 ; i++){
            if(score[i] == max) list.add(i+1);
        }
        answer = new int[list.size()];
        for(int i=0 ; i<answer.length ; i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}
