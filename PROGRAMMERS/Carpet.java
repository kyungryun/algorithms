class Carpet {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        int b = brown + yellow;
        for(int i=3 ; i<=(int)Math.sqrt(b) ; i++){
            if(b % i == 0){
                int n = b/i;
                if((i-2) * (n-2) == yellow){
                    answer[0] = n;
                    answer[1] = i;
                }
            }
        } 
        return answer;
    }
}
