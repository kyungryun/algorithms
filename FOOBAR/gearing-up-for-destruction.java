public class gearing-up-for-destruction {
    public static int[] solution(int[] pegs) {
        // Your code here
        int len = pegs.length;
        int []ans = {-1, -1};
        int sum = 0;
        for(int i=0 ; i<len-1; i++){
            if(i%2 == 0) sum += (pegs[i+1] - pegs[i]);
            else sum += -1*(pegs[i+1] - pegs[i]);
        }
        int a = sum*2;
        int b = 1;
        if(len%2 == 0){
            if(sum%3 == 0) a /= 3;
            else b= 3;
        }
        int x = a / b;
        for(int i=1 ; i<len ; i++){
            x = (pegs[i] - pegs[i-1]) - x;
            if(x < 1) return ans;
        }
        ans[0] = a;
        ans[1] = b;
        return ans;
    }
}
