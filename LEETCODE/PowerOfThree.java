public class PowerOfThree {
    public boolean isPowerOfThree(int n) {

        while(n%3==0 && n > 0){
            n/=3;
        }
        return n == 1;
    }
}