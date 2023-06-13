/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     int recurse(TreeNode* root){
        if (root == nullptr)return 0;
        
        int l = recurse(root->left);
        int r = recurse(root->right);
        
        return max(l, max(r, root->val));
    }
    
    void build_graph(TreeNode* root, vector<vector<int>>&graph){
        
         if(root == nullptr)return;
        
         if(root->left!= nullptr){
                graph[root->val].push_back(root->left->val);
                graph[root->left->val].push_back(root->val);
         }
        
          
         if(root->right!= nullptr){
                graph[root->val].push_back(root->right->val);
                graph[root->right->val].push_back(root->val);
         }
        
         build_graph(root->left, graph);
         build_graph(root->right, graph);
        
    }
    
   // int ans= 0;
    vector<int>temp;
    
    void dfs(int node, vector<vector<int>>&graph, vector<bool>&visited, int answer, int k){
        
        
       // ans = max(answer, ans);
   
        if(answer == k){
             temp.push_back(node);
        }
        visited[node] = true;
        
        for(int neigh : graph[node]){
           
            if(!visited[neigh]){
                dfs(neigh, graph, visited, answer+1,k);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(target==nullptr)return temp;
        int N = recurse(root)+1;
    
        vector<vector<int>>graph(N);
        build_graph(root, graph);
        
        vector<bool>visited(N, false);
        
        dfs(target->val, graph, visited,0, k);
        
        return temp;
    }
};
