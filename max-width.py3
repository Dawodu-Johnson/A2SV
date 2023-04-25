# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
#         if root == None:
#             return 0
        
#         def h(node):
#             if node == None:
#                 return 0

#             return 1 + max(h(node.left), h(node.right))

#         null, answer, height, depth = 404, 0, h(root), 1
        
#         queue = deque()
        
#         queue.append(root)        
        
#         while queue and depth <= height and depth <=3000:
         
#             # trim left for null values
#             while queue and queue[0].val == null:
#                 queue.popleft()
            
#             # trim right for null values
#             while queue and queue[-1].val == null:
#                 queue.pop()
                
            
#             # at this point we want a queue where the beginning and 
#             # end are actual element and may or may not contain null nodes in between 
#             depth+=1
#             size = len(queue)
#             answer = max(answer, size)
            
#             for i in range(size):

#                 val = queue.popleft()
                
# #                 if val.val == 404:
# #                     queue.append(TreeNode(null))
# #                     queue.append(TreeNode(null))
                
# #                 else:
                  
#                 if val.left !=None:
#                     queue.append(val.left)
#                 else:
#                     queue.append(TreeNode(null))

#                 if val.right !=None:
#                     queue.append(val.right)
#                 else:
#                     queue.append(TreeNode(null))


                    
#         return answer    # tle

        if root == None:
            return 0
        queue = deque()
        answer = 1
        queue.append([root,0])

        while queue:

            sz = len(queue)

            if sz >=2:
                answer = max(answer, queue[-1][1]-queue[0][1]+1)
            for i in range(sz):
                    
                st = queue.popleft()
              
                if st[0].left != None:
                    queue.append([st[0].left, st[1]*2+1])
                if st[0].right != None:
                    queue.append([st[0].right, st[1]*2+2])
        return answer
            
        
