// Pseudo-Palindromic Paths in a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int ans;

class Solution {
public:
    
    void helper(TreeNode* root, vector<int> count) {
        if(!root)
            return;
        if(!(root -> left) && !(root -> right)) {
            count[root -> val]++;
            int oddCount = 0;
            for(int i : count) {
                if(i&1)
                    oddCount++;
            }
            if(oddCount <= 1)
                ans++;
            return;
        }
        
        count[root -> val]++;
        helper(root -> left, count);
        helper(root -> right, count);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        ans = 0;
        helper(root, count);
        return ans;
    }
};