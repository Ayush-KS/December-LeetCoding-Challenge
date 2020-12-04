// Increasing Order Search Tree

class Solution {
public:
    TreeNode* ans;
    TreeNode* next;
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root -> left);
        if(!ans) {
            ans = root;
        } else {
            next -> right = root;
        }
        next = root;
        root -> left = NULL;
        inorder(root -> right);
    }
};