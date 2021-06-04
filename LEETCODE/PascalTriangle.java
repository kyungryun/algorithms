class PascalTriangle {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        if(numRows <= 0) return ans;
        
        List<Integer> step = new ArrayList<Integer>();
        step.add(1);
        ans.add(step);
        
        for(int i=1 ; i<numRows ; i++){
            List<Integer> cur = new ArrayList<Integer>();
            cur.add(1);
            for(int j=0 ; j<step.size()-1 ; j++){
                cur.add(step.get(j) + step.get(j+1));
            }
            cur.add(1);
            ans.add(cur);
            step = cur;
        }
       
        return ans;
    }
}
