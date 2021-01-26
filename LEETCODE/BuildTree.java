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
class BuildTree {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, 0, inorder.length-1);
    }

    public TreeNode build(int[] preorder, int[] inorder, int preIdx, int startIdx, int endIdx){
        if(preIdx >= preorder.length || startIdx > endIdx) return null;
        
        TreeNode node = new TreeNode(preorder[preIdx]);
        int idx = 0;
        for(int i=startIdx ; i<=endIdx ; i++){
            if(inorder[i] == node.val){
                idx = i;
                break;
            }
        }
        
        node.left = build(preorder, inorder, preIdx+1, startIdx, idx-1);
        node.right = build(preorder, inorder, preIdx + idx - startIdx + 1, idx+1, endIdx);
        return node;
    }
}
