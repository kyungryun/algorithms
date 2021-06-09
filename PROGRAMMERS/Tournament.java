class Tournament
{
    public int solution(int n, int a, int b)
    {
        int ans = 1;
        int left = a;
        int right = b;
        
        if(a>b){
            left = b;
            right = a;
        }
        
        while(left % 2 == 0 || right - left != 1){
            
            left = (left + 1) / 2;
            right = (right + 1 ) / 2;
            ans++;
        }
        return ans;
    }
}
