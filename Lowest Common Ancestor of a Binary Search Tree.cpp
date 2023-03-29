# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        #the idea is that it must be greater_equal to left and lesser_equal to right
        val_p = p.val
        val_q = q.val
        
        while root!=None:
            
            val = root.val
            
            if val > max(val_p, val_q):
                root = root.left
            elif val < min(val_p, val_q):
                root = root.right
            
            else:
                return root
        
        return root
    
        
