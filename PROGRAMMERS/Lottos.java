class Lottos {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {};
        int zero = 0;
        int num = 0;
        for(int lot : lottos){
            if(lot == 0){
                zero++;
            }else{
                for(int win:win_nums){
                    if(win == lot){
                        num++;
                        break;    
                    }
                }
            }
        }
        answer = new int[2];
        answer[0] = 7 - Math.max(num + zero, 1);
        answer[1] = 7 - Math.max(num, 1);
        return answer;
    }
}
