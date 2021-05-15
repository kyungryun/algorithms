class Collatz {
    public int solution(int num) {
        int cnt = 0;
        long n = num;
        while(true){
            if(n == 1 || cnt > 500) break;
            
            if(n%2 == 0){
                n/= 2;
            }else{
                n = n*3 + 1;
            }
            cnt++;
        }
        return cnt > 500 ? -1 : cnt;
    }
}
