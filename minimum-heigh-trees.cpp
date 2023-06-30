class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n ==1)return {0};
        
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        //0-1-2-3-4-5-6
            
        for(auto& edge: edges){
             graph[edge[0]].push_back(edge[1]);
             graph[edge[1]].push_back(edge[0]);
             indegree[edge[0]]++;
             indegree[edge[1]]++;
        }
        
        queue<int>process;
        int answer = n;
        
        for(int i = 0; i < n ;i++){
             if(indegree[i] == 1){
                  process.push(i);
             }
        }
        
        vector<int>ans;
        
        while( answer > 2){
             
            int  sz = process.size(); 
            answer -= sz;
         
            while(sz--){
                
                int node = process.front(); process.pop();
                
                for(auto& children: graph[node]){
                    
                    if(--indegree[children] == 1){
                         process.push(children);
                    }
               }
            }
            
        }
       
        while(!process.empty()){
             ans.push_back(process.front());
             process.pop();
        }
        
        return ans;
    }
};
