# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        # intersting problem. The key observation is that they must have the same column.
        
        store = []
        
        def recurse(node, x, y):
            
            if node == None:
                return 
            
            #looks like pre-order
            store.append([x,y, node.val])
            
            recurse(node.left, x+1, y-1)
            recurse(node.right, x+1, y+1)
        
        recurse(root, 0,0)
        
        dictionary = {}
        
        for val in store:
           
            if val[1] in dictionary:
                dictionary[val[1]].append( [val[0], val[2] ] )
                
            else:
                dictionary[val[1]] =[ [val[0], val[2]] ]
           
        
        dictionary = dict(sorted(dictionary.items()))
        
        answer = []
        
        for val in dictionary:
            t = sorted(dictionary[val])
            tt = []
            for v in t:
                tt.append(v[1])
          
            answer.append(tt)
        return answer
            
        
