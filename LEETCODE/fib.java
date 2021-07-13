class Solution {
    public int fib(int n) {
        int n1 = 0;
        int n2 = 1;
        int ans = 1;
        
        for(int i=2 ; i<=n ; i++){
            ans = n1 + n2;
            
            n1 = n2;
            n2 = ans;
        }
        
        return n == 0 ? 0 : ans;
    }
}
