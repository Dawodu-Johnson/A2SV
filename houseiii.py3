# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        @lru_cache(None)
        def recurse(node):
            
            if node == None :
                return 0
            
            rob , dontrob = 0, 0
            
            rob = node.val
            
            if node.left!=None:
                rob+=recurse(node.left.left)
                rob+=recurse(node.left.right)
            if node.right!=None:
                rob+=recurse(node.right.left)
                rob+=recurse(node.right.right)
            
            dontrob = recurse(node.left)+recurse(node.right)     
                   
            return max(rob, dontrob)
        
        return recurse(root)
