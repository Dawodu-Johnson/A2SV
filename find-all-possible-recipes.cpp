class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        queue<string>process;
        vector<string>answer;
        
        for(int i = 0; i < ingredients.size(); i++) {
            
             for(auto& ing: ingredients[i]) {
                   
                 graph[ing].push_back(recipes[i]);
                 indegree[recipes[i]]++;
             }
        }
        
        for(int i = 0; i < supplies.size(); i++) {
              process.push(supplies[i]);
        }
        
        while(!process.empty()) {
            
            string top = process.front(); process.pop();
            
            for(string& r: graph[top]) {
                  if(--indegree[r] == 0) {
                       process.push(r);
                  }
            }
            
        }
        
        for(int i = 0; i < recipes.size(); i++) {
            if(indegree[recipes[i]] == 0){
                  answer.push_back(recipes[i]);
            }
        }
        
        return answer;
        
    }
};
