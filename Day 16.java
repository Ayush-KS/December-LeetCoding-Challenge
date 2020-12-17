// Validate Binary Search TreeNode

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
class Solution {
    List<Integer> inord = new ArrayList<Integer>();
    public void inorder(TreeNode root) {
        if(root == null)
            return;
        inorder(root.left);
        inord.add(root.val);
        inorder(root.right);
    }
    public boolean isValidBST(TreeNode root) {
        inorder(root);
        for(int i = 1; i < inord.size(); i++) {
            if(inord.get(i) <= inord.get(i - 1))
                return false;
        }
        return true;
    }
}