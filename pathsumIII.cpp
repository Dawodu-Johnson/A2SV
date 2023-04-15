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
    long long single_node_sum(TreeNode* root, long long sum, int targetSum){
        if(root == nullptr)return 0;
        
        int answer = 0;
        sum+=root->val;
        if(sum == targetSum)answer+=1;
        return answer+single_node_sum(root->left,sum, targetSum)+single_node_sum(root->right, sum, targetSum);
    }
    
    int all_nodes_sum(TreeNode* root, int targetSum){
        if(root == nullptr)return 0;
        return single_node_sum(root, 0ll, targetSum) + all_nodes_sum(root->left,  targetSum)+ all_nodes_sum(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        return all_nodes_sum(root,targetSum);
    }
};
