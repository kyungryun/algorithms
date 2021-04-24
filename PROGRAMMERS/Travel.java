import java.util.*;
class Travel {
    List<String> answers;
    boolean[] visited;
    public String[] solution(String[][] tickets) {
        answers = new ArrayList<>();
        visited = new boolean[tickets.length];
        dfs(0, "ICN", "ICN", tickets);
        Collections.sort(answers);
        String[] answer = answers.get(0).split(",");
        return answer;
    }
    
    public void dfs(int cnt, String now, String ans, String[][] tickets){
        if(cnt == tickets.length){
            answers.add(ans);
            return;
        }
        for(int i=0 ; i<tickets.length ; i++){
            if(!visited[i] && tickets[i][0].equals(now)){
                visited[i] = true;
                dfs(cnt+1, tickets[i][1], ans+","+tickets[i][1], tickets);
                visited[i] = false;
            }
        }
        return;
    }
}
