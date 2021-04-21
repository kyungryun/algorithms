import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DP_4811 {
    // 재귀
    public static long solved(long[][] d, int full, int half){
        if(d[full][half] > 0) return d[full][half];
        if(full == 0) return 1;
        if(half == 0) return d[full][half] = solved(d,full-1, half+1);
        else return  d[full][half] = solved(d, full-1, half+1) + solved(d, full, half-1);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] dp = new long[31];
        long[][] d = new long[31][31];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3 ; i<=30 ; i++){
            long cnt = 0;
            for(int j=0 ; j<i ; j++){
                cnt += dp[j]*dp[i-j-1];
            }
            dp[i] = cnt;
        }
        while(true){
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            System.out.println(dp[n]);
//            solved(d,n,0);
//            System.out.println(d[n][0]);
        }

    }
}
