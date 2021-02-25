class EvalRPN {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0 ; i<tokens.length ; i++){
            if(tokens[i].equals("+")){
                stack.push(stack.pop() + stack.pop());
            }else if(tokens[i].equals("-")){
                stack.push(-stack.pop() + stack.pop());
            }else if(tokens[i].equals("*")){
                stack.push(stack.pop() * stack.pop());
            }else if(tokens[i].equals("/")){
                int temp = stack.pop();
                stack.push(stack.pop() / temp);
            }else{
                stack.push(Integer.parseInt(tokens[i]));
            }
        }
        
        return stack.pop();
    }
}
