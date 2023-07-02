class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>>vis(row, vector<bool>(col, false));
        vector<pair<int, int>>dir = { {0,1}, {0,-1}, {-1,0}, {1,0} };
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] ==2){
                    q.push({i,j});
                }
            }
        }
        
        int answer = 0;
        
        while(!q.empty()) {
            
            int sz = q.size();
           
            for(int i = 0; i < sz; i++) {
                
                auto [x, y] = q.front(); q.pop();
                vis[x][y] = true;
            
                
                for(auto& directions : dir) {
                     int m = directions.first + x , n = directions.second + y;
                     if(m < 0 or m >= row or n < 0 or n >=col or grid[m][n] ==0 or vis[m][n] or grid[m][n] ==2)continue;
                     vis[m][n] = true;
                     grid[m][n] = 2;
                     q.push({m,n});
                }
            } 
            
            if(!q.empty())answer+=1;
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0 ;j < col; j++){
                 if(grid[i][j] ==1)return -1;
            }
        }
        return answer;
        
    }
};
