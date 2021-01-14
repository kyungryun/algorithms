public class ReverseInteger {
    public int reverse(int x) {
        int ans = 0;

        while(x != 0){
            int now = x % 10;
            int limit = Integer.MAX_VALUE/10;
            if(ans > Integer.MAX_VALUE/10 || (ans == Integer.MAX_VALUE/10 && now > 7)) return 0;
            if(ans < Integer.MIN_VALUE/10 || (ans == Integer.MIN_VALUE/10 && now < -8)) return 0;
            ans = ans*10 + now;
            x/=10;

        }
        return ans;
    }
}
