import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DP_15486 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N+1];
        int[] P = new int[N+1];
        int[] dp = new int[N+1];
        int ans = 0;
        for(int i=0 ; i<N ; i++){
            st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=0 ; i<N + 1 ; i++){
            ans = Math.max(ans, dp[i]);
            if(i + T[i] >= N + 1) continue;
            dp[i + T[i]] = Math.max(ans + P[i], dp[i + T[i]]);
        }
        System.out.println(ans);
    }
}
