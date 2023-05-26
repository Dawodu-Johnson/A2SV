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
    vector<string>answer;
    
    void solve(TreeNode* root, string value){
         
         if(root==nullptr)return;
         
         else if(root!=nullptr && root->left==nullptr && root->right==nullptr){
               string temp= value+ to_string(root->val);
               answer.push_back(temp);
         }
        
         else{
              solve(root->left, value+to_string(root->val));
              solve(root->right, value+to_string(root->val));
         }
        
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,"");
          for(const string&s: answer){
               stringstream ss;
               ss << s;
               int temp;
               ss >> temp;
               ans+=temp;
          }
        
        return ans;
    }
};
