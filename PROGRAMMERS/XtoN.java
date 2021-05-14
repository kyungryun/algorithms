class XtoN {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        int idx = 0;
        long cur = x;
        while(idx < n){
            answer[idx++] = cur;
            cur += x;
        }
        
        
        return answer;
    }
}
