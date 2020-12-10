# Binary Search Tree Iterator

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    st = list()
    
    def addLeft(self, root):
        while(root):
            self.st.append(root)
            root = root.left

    
    def __init__(self, root: TreeNode):
        self.addLeft(root)

    def next(self) -> int:
        ans = self.st.pop()
        
        if(ans.right):
            self.addLeft(ans.right)
        
        return ans.val

    def hasNext(self) -> bool:
        return self.st


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()