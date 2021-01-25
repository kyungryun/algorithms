public class NestedIterator implements Iterator<Integer> {

    Queue<Integer> q;
    public NestedIterator(List<NestedInteger> nestedList) {
        q = new LinkedList<>();
        enqueue(nestedList);
        
    }
    private void enqueue(List<NestedInteger> nestedList){
        for(NestedInteger nested: nestedList){
            if(nested.isInteger()){
                q.add(nested.getInteger());
            }else{
                enqueue(nested.getList());
            }
        }
    }

    @Override
    public Integer next() {
        return q.poll();
    }

    @Override
    public boolean hasNext() {
        return !q.isEmpty();
    }
}
