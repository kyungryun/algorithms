class MyQueue {

    Stack<Integer> inQueue;
    Stack<Integer> outQueue;
    
    /** Initialize your data structure here. */
    public MyQueue() {
        inQueue = new Stack<>();
        outQueue = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        inQueue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(outQueue.empty()){
            trans();
        }
        return outQueue.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(outQueue.empty()){
            trans();
        }
        return outQueue.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return inQueue.empty() && outQueue.empty();
    }
    
    private void trans(){
        while(!inQueue.empty()){
            outQueue.push(inQueue.pop());
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
