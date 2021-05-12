class KeyPad {
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int leftPos = 10;
        int rightPos = 12;
        for(int number : numbers){
            if(number == 1 || number == 4 || number == 7){
                sb.append("L");
                leftPos = number;
            }else if(number == 3 || number == 6 || number == 9){
                sb.append("R");
                rightPos = number;
            }else{
                if(number == 0) number += 11;
                int leftDist = (Math.abs(number-leftPos))/3 + (Math.abs(number-leftPos))%3;
                int rightDist = (Math.abs(rightPos-number))/3 + (Math.abs(rightPos-number))%3;
                if(leftDist == rightDist){
                    if(hand.equals("right")){
                        sb.append("R");
                        rightPos = number;
                    }else{
                        sb.append("L");
                        leftPos = number;
                    }
                }else if(leftDist > rightDist){
                    sb.append("R");
                    rightPos = number;
                }else{
                    sb.append("L");
                    leftPos = number;
                }
            }
        }
        return sb.toString();
    }
}
