class ZigzagLevelOrder {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>();
        
        if(root == null) return ans;
        
        q.add(root);
        boolean dir = true;
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> cur = new ArrayList<>();
            for(int i=0 ; i<size ; i++){
                TreeNode node = q.poll();
                if(dir){
                    cur.add(node.val);
                }else{
                    cur.add(0, node.val);
                }
                
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            ans.add(cur);
            dir = !dir;
        }
        
        return ans;
    }
}
