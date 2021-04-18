class Square {
    public long solution(int w, int h) {
        long answer = 1;
        int gcd = 1;
        for(int i= w>h ? w : h ; i>0 ; i--){
            if(w%i == 0 && h % i == 0){
                gcd = i;
                break;
            }
        }
        return (long)w * (long)h - gcd*((w/gcd + h/gcd) - 1);
    }
}
