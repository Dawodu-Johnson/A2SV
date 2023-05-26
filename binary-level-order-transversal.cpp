/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
         vector<vector<int>> answer;
         
         if(root==nullptr)return answer;
        
         queue<TreeNode* > store;
        
         store.push(root);
             
                while(!store.empty()){
                    // pop_it out inside a temporary vector.
                    int size= store.size();
                    vector<int>values;
                    
                     for(int index=0; index < size; index++){
                          
                          TreeNode* temp = store.front();
                          store.pop();
                          values.push_back(temp->val);
                          
                          if(temp->left!=nullptr)store.push(temp->left);
                          if(temp->right!=nullptr)store.push(temp->right);
                         
                     }
                    
                    answer.push_back(values);
                }
        
         return answer;
    }
};
