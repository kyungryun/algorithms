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
class KthSmallest {
    int ans = 0;
    int cnt = 0;
    public int kthSmallest(TreeNode root, int k) {
        cnt = k;
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode node){
        if(node == null) return;
        inorder(node.left);
        cnt--;
        if(cnt == 0){
            ans = node.val;
            return;
        }
        inorder(node.right);
    }
}
