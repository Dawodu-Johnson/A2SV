class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix[0].size();
        
        priority_queue<int>store;
        
        for(int i=0; i< n; i++){
              
              for(int j=0; j < n; j++){
                   store.push(matrix[i][j]);
                   if(store.size() >k)store.pop();
              }
        }
        
        
        return store.top();
    }
};
