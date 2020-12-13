# Smallest Subtree with all the Deepest Nodes

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        
        def dfs(root):
            if not root:
                return 0,0
            left, right = dfs(root.left), dfs(root.right)
            if(left[1] > right[1]):
                return left[0], left[1] + 1
            elif(right[1] > left[1]):
                return right[0], right[1] + 1
            else:
                return root, left[1] + 1
        
        return dfs(root)[0]