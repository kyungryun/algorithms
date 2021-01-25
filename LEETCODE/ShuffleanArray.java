class ShuffleanArray {

    int[] org;
    int[] rand;
    public Solution(int[] nums) {
        org = nums;
        rand = nums.clone();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        Random r = new Random();
        for(int i=0 ; i<rand.length ; i++){
            int temp = r.nextInt(rand.length);
            swap(i, temp);
        }
        
        return rand;
    }
    
    private void swap(int i, int j){
        int temp = rand[i];
        rand[i] = rand[j];
        rand[j] = temp;
    }
}
