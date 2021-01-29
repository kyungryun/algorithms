class RandomizedSet {

    Set<Integer> set;
    Random rand;
    /** Initialize your data structure here. */
    public RandomizedSet() {
        set = new HashSet<>();
        rand = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(set.contains(val)) return false;
        set.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!set.contains(val)) return false;
        set.remove(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        int idx = 0;
        int r = rand.nextInt(set.size());
        for(int i : set){
            if(idx++ == r) return i;
        }
        return 0;
    }
}
