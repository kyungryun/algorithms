class PAndY {
    boolean solution(String s) {
        int cnt = 0;
        
        for(int i=0 ; i<s.length() ; i++){
            if(s.charAt(i) == 'p' || s.charAt(i) == 'P') cnt++;
            else if(s.charAt(i) == 'y' || s.charAt(i) == 'Y') cnt--;
        }

        return cnt == 0;
    }
}
