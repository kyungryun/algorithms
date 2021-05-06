class Harshad {
    public boolean solution(int x) {
        int sum = 0;
        int tmp = x;
        while(x > 0){
            sum += x%10;
            x /= 10;
        }
        return tmp%sum == 0;
    }
}
