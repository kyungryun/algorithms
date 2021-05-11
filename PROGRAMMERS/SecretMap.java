class SecretMap {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i=0 ; i<n ; i++){
            StringBuilder sb = new StringBuilder();
            for(int j=n-1 ; j>=0 ; j--){
                int a = (arr1[i]>>j)&1;
                int b = (arr2[i]>>j)&1;
                int c = a|b;
                if(c == 0) sb.append(" ");
                else sb.append("#");
            }
            answer[i] = sb.toString();
        }
        return answer;
    }
}
