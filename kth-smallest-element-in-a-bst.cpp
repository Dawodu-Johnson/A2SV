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
    int answer = 0, val = 0;
    void recurse(TreeNode* root, int k){
        
        if(root == nullptr)return;
       
    
        recurse(root->left, k);
        val++;
        if(val == k){
             answer = root->val;
             return;
        }
        val++; // root
        recurse(root->right, k);
            
    }
    
    int kthSmallest(TreeNode* root, int k) {
        recurse(root, k);
        return answer;
    }
};
