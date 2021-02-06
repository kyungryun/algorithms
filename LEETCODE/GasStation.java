class GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int cur = 0;
        int tank = 0;
        int idx = 0;
        for(int i=0 ; i<gas.length ; i++){
            int diff = gas[i] - cost[i];
            tank += diff;
            cur += diff;
            if(tank < 0){
                tank = 0;
                idx = i+1;
            }
        }
        
        return cur < 0 ? -1 : idx;
    }
}
