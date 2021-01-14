import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<String>();
        generate(n, "", 0, 0, ans);
        return ans;
    }

    public void generate(int n, String now, int open, int close, List<String> ans){
        if(open == n && close == n){
            ans.add(now);
            return;
        }
        if(open < n){
            generate(n, now + "(", open+1, close, ans);
        }

        if(close < open){
            generate(n, now + ")", open, close+1, ans);
        }

    }
}
