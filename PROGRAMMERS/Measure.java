class Measure {
    int measure(int num){
        int cnt = 0;
        for(int i=1 ; i<=num ; i++){
            if(num%i == 0) cnt++;
        }
        return cnt;
    }
    public int solution(int left, int right) {
        int answer = 0;
        
        for(int i=left ; i<=right ; i++){
            if(measure(i) % 2 == 0) answer += i;
            else answer -= i;
        }
        return answer;
    }
}
