class BinaryCompress {
    public int[] solution(String s) {
        int[] answer = new int[2];
        int stage = 0;
        int zero = 0;
        
        // 1번풀이
        while(!s.equals("1")){
            StringBuilder sb = new StringBuilder();
            for(int i=0 ; i<s.length() ; i++){
                char c = s.charAt(i);
                if(c == '1') sb.append(c);
            }
            answer[1] += (s.length() - sb.toString().length());
            answer[0]++;
            s = Integer.toBinaryString(sb.toString().length());
        }
        
        // 2번풀이 느림 StringBuilder 쓸것
        while(true){
            stage++;
            int one = 0;
            String temp = "";
            for(int i=0 ; i<s.length() ; i++){
                char c = s.charAt(i);
                if(c == '0') zero++;
                else temp += "1";
            }
            temp = Integer.toBinaryString(temp.length());
            if(temp.length() == 1) break;
            s = temp;
            
        }
        answer[0] = stage;
        answer[1] = zero;
        return answer;
    }
}
