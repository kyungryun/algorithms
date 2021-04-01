class Network {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] flag = new boolean[n];
        for(int i=0 ; i<n ; i++){
            if(!flag[i]){
                answer++;
                dfs(i, flag, computers);
            }
        }
        return answer;
    }
    
    public void dfs(int computer, boolean[] flag, int[][] computers){
        flag[computer] = true;
        for(int i=0 ; i<computers.length ; i++){
            if(!flag[i] && computers[computer][i] == 1){
                dfs(i, flag, computers);
            }
        }
    }
}
