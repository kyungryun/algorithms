class FindLucky {
    public int findLucky(int[] arr) {
        int []num = new int[501];
        
        for(int i=0 ; i<arr.length ; i++){
            num[arr[i]]++;
        }
        
        for(int i=num.length-1 ; i>0 ; i--){
            if(num[i] == i) return i;
        }
        
        return -1;
    }
}
