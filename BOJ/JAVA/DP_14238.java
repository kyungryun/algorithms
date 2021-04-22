import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DP_14238 {
    public static boolean[][][][][]dp;
    public static boolean check = false;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int aCnt = 0;
        int bCnt = 0;
        int cCnt = 0;

        for(int i=0 ; i<str.length() ; i++){
            if(str.charAt(i) == 'A') aCnt++;
            else if(str.charAt(i) == 'B') bCnt++;
            else cCnt++;
        }

        dp = new boolean[aCnt+1][bCnt+1][cCnt+1][3][3];
        solved(aCnt, bCnt, cCnt, "", 0, 0);
        if(!check) System.out.println(-1);
    }
    public static void solved(int a, int b, int c, String s , int prev2, int prev){
        if(a == 0 && b == 0 && c == 0){
            System.out.println(s);
            check = true;
            return;
        }
        if(dp[a][b][c][prev2][prev]) return;
        dp[a][b][c][prev2][prev] = true;

        if(a > 0)  solved(a-1,b,c,s + 'A', prev,0);
        if(b > 0 && prev != 1) solved(a, b-1, c, s + 'B', prev, 1);
        if(c > 0 && prev != 2 && prev2 != 2) solved(a, b, c-1, s+'C', prev, 2);

    }
}
