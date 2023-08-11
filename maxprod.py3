# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        
        def _sum(node) -> int:
            if node == None:
                return 0
            
            return node.val + _sum(node.left) + _sum(node.right)
        
        value = _sum(root)
 
        answer = 0
        def _solve(node) -> int:
            nonlocal answer
            if node == None:
                return 0
           
            left = _solve(node.left)
            answer = max(answer, left *(value-left));
            right = _solve(node.right)
            answer = max(answer, right* (value-right));
            return node.val + left + right
        
        temp = _solve(root)
        
        return answer% (10**9 + 7);
    
            
            
            
            
            
