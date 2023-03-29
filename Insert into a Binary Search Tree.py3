# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        
        
        if root==None:
            return TreeNode(val)
        
        def recurse(node):
            
            if node==None:
                return
            
            elif node.left ==None and node.val > val:
                node.left = TreeNode(val)
                return
            
            elif node.right ==None and node.val < val:
                node.right = TreeNode(val)
                return
            
            elif node.val > val:
                recurse(node.left)
            
            else:
                recurse(node.right)
        
        recurse(root)
        
        return root
            
