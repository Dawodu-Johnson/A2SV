class Solution {
public:
    vector<pair<int,int>>dir;
    
   /* int solve(int row, int col, vector<vector<int>>&grid, vector<vector<bool>>&visited){
        
        if(row == grid.size()-1 and col ==grid[0].size()-1 and grid[row][col]==0)return 1;
        if(row < 0 or col < 0 or row >= grid.size() or col  >= grid[0].size() or grid[row][col]==1 or visited[row][col])return 101;
        
        
        visited[row][col] = true;
        
        int temp = 101, answer = 1;
        for(auto& d: dir){
            
             int x = d.first+row, y = d.second + col;
             temp = min(temp, solve(x,y, grid, visited));
             
        }
        visited[row][col] = false;
       return answer+temp;
    }*/
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        dir = {{0,1},{0,-1}, {1,0}, {-1,0}, {1,-1},{1,1}, {-1,1}, {-1,-1}};
        
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(),false));
        
        queue<pair<int,int>>store;
        int row = grid.size(), col = grid[0].size(), answer = 0;
        if(grid[0][0]!=0 or grid[row-1][col-1]!=0)return -1;
        
        store.push({0,0});
        
        
        while(!store.empty()){
            
            int sz = store.size();
            answer++;
            
            for(int i = 0; i <sz; i++){
                
                int x = store.front().first, y = store.front().second;
                store.pop();
                if(x == row-1 and col-1 == y)return answer;
                
                for(int j = 0; j < 8; j++){
                     
                      x = x + dir[j].first;
                      y = y + dir[j].second;
                      
                      if(x >=0 and y >=0 and x < row and y < col and !visited[x][y] and grid[x][y] == 0){
                            
                           visited[x][y] = true;
                           store.push({x,y});
                           
                      }
                    
                      x = x - dir[j].first;
                      y = y - dir[j].second;
                }
            }
            
        }
        
        return -1;
      
    }
};
