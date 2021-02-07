class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] arr = new int[amount+1];      
        arr[0] = 0;
        for(int i=1 ; i<arr.length ; i++){
            arr[i]=amount+1;
            for(int j=0 ; j<coins.length ; j++){
                if(i>=coins[j]){
                    arr[i] = Math.min(arr[i], arr[i-coins[j]]+1);
                }
            }
        }
        
        return arr[amount] > amount? -1 : arr[amount];
    }
}
