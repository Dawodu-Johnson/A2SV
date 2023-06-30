# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        answer = []
        
        def transverse(root):
            
            if root == None:
                return
            # left root right 
            
            transverse(root.left)
            
            answer.append([root.val, root])
            
            transverse(root.right)
        
        transverse(root)
        copy = answer.copy()
        answer.sort()
        
        for i in range(len(copy)):
            if copy[i][0]!= answer[i][0]:
               
                t = copy[i][0]
                copy[i][1].val = answer[i][1].val
                answer[i][1].val = t
                break
                
        
        
