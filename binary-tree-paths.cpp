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
    vector<vector<int>>store;
    void recurse(TreeNode* root, vector<int>&val){
        
        if(root == nullptr)return ;
        val.push_back(root->val);
        if(root!= nullptr && root->left == nullptr and root->right==nullptr){
             store.push_back(val);
        }
        
        recurse(root->left,val);
        recurse(root->right,val);
        val.pop_back();
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>answer;
        vector<int>temp;
        
        recurse(root, temp);
        
        for(const auto&x: store){
             string temp;
             for(int y: x){
                  if(temp.empty()){
                       temp+=to_string(y);
                  }
                 else{
                      temp+="->";
                      temp+=to_string(y);
                 }
             }
             answer.push_back(temp);
        }
        return answer;
    }
};
