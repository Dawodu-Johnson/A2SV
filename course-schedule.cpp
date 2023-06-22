class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int>indegrees(numCourses,0);
            vector<vector<int>>graph(numCourses);
        
            for(const auto& pre: prerequisites){ 
                 indegrees[pre[1]]++;
                 graph[pre[0]].push_back(pre[1]);
            }
        
            queue<int>process;
            int counter = 0;
        
            for(int i=0; i < indegrees.size(); i++){
                 if(indegrees[i] == 0)process.push(i);
            }
        
            while(!process.empty()){
                
                 int node = process.front();
                 process.pop();
                 counter++;
                
                 for(auto& neigh: graph[node]){
                       if(--indegrees[neigh]==0){
                           process.push(neigh);
                       }
                 }
                
            }
        
           if(numCourses!= counter)return false;
        
           return true;
    }
};
