class WaterBottles {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        
        while(numBottles/numExchange != 0){
            int a = numBottles / numExchange;
            int b = numBottles % numExchange;
            ans += a;
            numBottles = a + b;
        }
        
        return ans;
    }
}
