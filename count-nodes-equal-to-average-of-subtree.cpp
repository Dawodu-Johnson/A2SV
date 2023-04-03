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

struct Node{
      int sum;
      int count;
    
      Node(int s, int c): sum(s),count(c){}
};
// we are using a node because we need some information.

class Solution {
public:
    int answer=0;
    Node* postorder(TreeNode* root){
        
         if(root==nullptr){
              return new Node(0,0);
         }
        
         Node* left= postorder(root->left);
         Node* right= postorder(root->right);
        
         Node* current = new Node(root->val+ left->sum + right->sum, 1+left->count+ right->count);
         
         int average = current->sum/ (current->count);
         
         if(average== root->val)++answer;
         
         return current;
    }
    int averageOfSubtree(TreeNode* root) {
         Node* store = postorder(root);
         return answer;
        
    }
};
