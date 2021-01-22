public class Solution {
    public static int ans = 0;
    public static void permutation(int[] l, int[] num, boolean[] visited, int idx, int n, int r){
        if(idx == r){
            int cur = 0;
            for(int i=0 ; i<r ; i++){
                cur *= 10;
                cur += num[i];
            }
            System.out.println(cur);
            ans = cur%3 == 0 ? Math.max(ans, cur) : ans;
            return;
        }
        for(int i=0; i<n ; i++){
            if(!visited[i]){
                visited[i] = true;
                num[idx] = l[i];
                permutation(l, num, visited, idx+1, n, r);
                visited[i] = false;
            }
        }
    }
    public static int solution(int[] l) {
        // Your code here
        int len = l.length;
        for(int i=1 ; i<=len ; i++){
            boolean []visited = new boolean[len];
            int []num = new int[len];
            permutation(l, num, visited, 0, len, i);
        }

        return ans;
    }
}