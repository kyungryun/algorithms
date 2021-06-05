class JoyStick {
    public int solution(String name) {
        int answer = 0;
        int l = name.length();
        int min = l-1;
        for(int i=0 ; i<l ; i++){
            char c = name.charAt(i);
            if(c-'A' < 'Z' - c + 1){
                answer += (c-'A');
            }else{
                answer += ('Z' - c + 1);
            }
            int next = i + 1;
            
            while(next < l && name.charAt(next) == 'A') next++;
            
            min = Math.min(min, (i*2) + l - next);
        }
        
        answer += min;
        return answer;
    }
}
