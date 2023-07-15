# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        
            inorder = preorder.copy()
            inorder.sort()
            
            def buildTree(preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

                if not preorder or not inorder:
                    return None

                root = TreeNode(preorder[0])
                pivot = inorder.index(preorder[0])
                root.left = buildTree(preorder[1:pivot+1], inorder[:pivot])
                root.right = buildTree(preorder[pivot+1:], inorder[pivot+1:])
                return root

            return buildTree(preorder, inorder)
