class twoNumSum {
    public long solution(int a, int b) {
        long answer = 0;
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        // 등차수열의 합
        // return (b - a + 1) * (a + b) / 2;
        for(long i=a ; i<=b ; i++){
            answer += i;
        }
        return answer;
    }
}
