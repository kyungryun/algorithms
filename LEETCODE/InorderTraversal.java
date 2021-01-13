class InorderTraversal {
    
    void inorder(List<Integer> ans, TreeNode tree){
        if(tree == null) return;
        
        inorder(ans, tree.left);
        ans.add(tree.val);
        inorder(ans, tree.right);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        inorder(ans, root);
        return ans;
    }
}
