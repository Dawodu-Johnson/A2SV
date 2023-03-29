# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        
        def recurse(node):
            
            if node==None:
                return None
            
            elif node.val == val:
                return node
            
            elif node.val > val:
                
                return recurse(node.left)
            
            else:
                return recurse(node.right)
        
        return recurse(root)
    
