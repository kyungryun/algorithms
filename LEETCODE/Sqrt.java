public class Sqrt {

    public int mySqrt(int x) {
        int left = 0;
        int right = x;

        while(left < right){
            long mid = (left + right) / 2;

            if(mid*mid == x) return (int)mid;
            else if(mid*mid > x) right = (int)mid-1;
            else left = (int)mid + 1;
        }
        return right;
    }
}
