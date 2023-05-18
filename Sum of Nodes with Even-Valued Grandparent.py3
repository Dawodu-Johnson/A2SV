# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        
        answer = 0
        
        def recurse(node):
            nonlocal answer
            
            if node == None:
                return
            
            if node.left!=None:
                if node.val%2 == 0:
                    if node.left.left!=None :
                          answer+=node.left.left.val
                    if node.left.right!=None:
                          answer+=node.left.right.val
            
            if node.right!=None:
                if node.val%2 == 0:
                    if node.right.left!=None: 
                        answer+=node.right.left.val
                    
                    if node.right.right!=None:
                        answer+=node.right.right.val
        
                    
                    
            
            recurse(node.left)
            recurse(node.right)
            
        recurse(root)
        return answer
