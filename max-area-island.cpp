class Solution {
public:
     bool valid (int r, int c, int r1, int c1){
        
          if(r <0 || r >=r1 || c <0 || c >=c1) return false;
        
          return true;
    }
    
    vector<pair<int,int>>dx_dy;
    
    int dfs(int sr, int sc, vector<vector<bool>>&visited, 
                             vector<vector<int>>&image){
          
        
           if(!valid(sr,sc, image.size(), image[0].size()) 
                    || visited[sr][sc] || image[sr][sc]==0)return 0;
           
           int answer =1;
           visited[sr][sc]= true;
          
           for(int i=0; i < 4; i++){
                   answer+= dfs(sr+dx_dy[i].first, sc+dx_dy[i].second, visited, image);
           }
        return answer;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
         dx_dy= {{-1,0},{1,0},{0,-1},{0,1}};
         
        
         vector<vector<bool>>visited
               (grid.size(), vector<bool>(grid[0].size(),false));
         int answer=0;
        
         for(int row=0; row < grid.size(); row++){
                   
                 for(int col =0; col < grid[0].size(); col++){
                     
                      if(grid[row][col]!=0  && !visited[row][col]){
                          //++answer;
                          answer=max(answer,dfs(row,col,visited,grid));
                      }
                 }
         }
        
       
        
          return answer;
    }
};
