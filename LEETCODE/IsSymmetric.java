/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class IsSymmetric {
    public boolean isSymmetric(TreeNode root) {
        
        if(root == null) return true;
        
        return check(root.left, root.right);
    
    }
    
    public boolean check(TreeNode leftTree, TreeNode rightTree){
        
        if(leftTree == null && rightTree == null) return true;
        if(leftTree != null && rightTree == null) return false;
        if(leftTree == null && rightTree != null) return false;
        
        if(leftTree.val != rightTree.val) return false;
        
        return check(leftTree.left, rightTree.right) && check(leftTree.right, rightTree.left);
    }
}
