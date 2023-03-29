# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        if root==None:
            return True
        
        
        def validate(node, left_val, right_val):
            
            if node == None:
                return True
            
            if node.val > left_val and node.val < right_val:
                return validate(node.left,left_val, node.val) and validate(node.right, node.val, right_val)
            else:
                return False
        
        return validate(root, float(-inf), float(inf))
