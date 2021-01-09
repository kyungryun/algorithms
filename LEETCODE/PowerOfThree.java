public class PowerOfThree {
    public boolean isPowerOfThree(int n) {

        while(n%3==0 && n > 0){
            n/=3;
        }
        return n == 1;
    }
    
    public boolean isPowerOfThree2(int n){
        double ans = Math.log10(n) / Math.log10(3);
        return (int) ans == ans;
    }
}
