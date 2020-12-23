// Balanced Binary Tree

class Solution {
public:
    bool ans;
    
    int height(TreeNode* root) {
        if(!root || !ans)
            return 0;
        int left = height(root -> left);
        int right = height(root -> right);
        if(abs(left - right) > 1) {
            ans = false;
        }
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        ans = true;
        height(root);
        return ans;
    }
};