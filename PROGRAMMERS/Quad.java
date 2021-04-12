class Quad {
    public void quad(int[][] arr, int r, int c, int len, int[] answer){
        
        int cur = arr[r][c];
        boolean compress = true;
        for(int i=r ; i<r+len ; i++){
            for(int j=c ; j<c+len ; j++){
                if(cur != arr[i][j]){
                    compress = false;
                    break;
                }
            }
        }
        
        if(compress){
            if(cur == 0) answer[0]++;
            else answer[1]++;
        }else{
            quad(arr, r, c, len/2, answer);
            quad(arr, r+len/2, c, len/2, answer);
            quad(arr, r, c+len/2, len/2, answer);
            quad(arr, r+len/2, c+len/2, len/2, answer);
        }
        
    }
    public int[] solution(int[][] arr) {
        int[] answer = new int[2];
        quad(arr, 0, 0, arr.length, answer);
        return answer;
    }
}
