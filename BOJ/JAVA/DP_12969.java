import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DP_12969 {

    private static int N;
    private static int K;
    private static final boolean[][][][]dp = new boolean[31][31][31][436];
    private static char[] str;
    public static boolean solved(int i, int a, int b, int p){
        if(i == N){
            return p == K;
        }
        if(dp[i][a][b][p]) return false;
        dp[i][a][b][p] = true;

        str[i] = 'A';
        if(solved(i+1, a+1, b, p))return true;

        str[i] = 'B';
        if(solved(i+1, a, b+1, p + a)) return true;

        str[i] = 'C';
        if(solved(i + 1, a, b, p + a + b)) return true;

        return false;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());

        N = Integer.parseInt(stk.nextToken());
        K = Integer.parseInt(stk.nextToken());

        str = new char[N];

        if(solved(0,0,0,0)) System.out.println(new String(str));
        else System.out.println(-1);
    }
}
