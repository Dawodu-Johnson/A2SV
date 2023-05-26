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
  
    vector<double> averageOfLevels(TreeNode* root) {
        
          queue<TreeNode*>store;
          vector<double>answer;
          store.push(root);
        
          while(!store.empty()){
                  int size  = store.size();
                  double sum = 0;
              
                  for(int i = 0; i < size; i++){
                      TreeNode* t = store.front();
                      if(t->left!=nullptr){
                          store.push(t->left);
                      }
                      if(t->right!=nullptr){
                           store.push(t->right);
                      }
                      store.pop();
                      
                      sum += t->val;
                  }
                 answer.push_back(sum/(double)size);
                  
          }
        
        return answer;
    }
};
