class Country124 {
    public String solution(int n) {
        String[] number = {"4","1","2"};
        String ans = "";
        
        int cnt = n;
        
        while(cnt > 0){
            int rem = cnt % 3;
            cnt/=3;
            if(rem == 0) cnt--;
            
            ans = number[rem] + ans;
            
        }
          
        return ans;
    }
}
