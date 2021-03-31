class TargetNumber {
    public static int solution(int[] numbers, int target) {
        dfs(numbers, target, 0, 0);
        return count;
    }
    static int count = 0;
    public static void dfs(int[] numbers,int target,int deep,int res) {

        if(deep == numbers.length) {
            if(res == target) {
                count++;
                return;
            }else {
                return;
            }
        }

        dfs(numbers, target, deep+1,res+numbers[deep]);

        dfs(numbers, target, deep+1,res-numbers[deep]);
    }
}
