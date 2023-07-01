class Solution {
public:
    vector<vector<int>>result;
    vector<vector<bool>>visited;
    vector<pair<int, int>>dir;
    queue<pair<int, int>>q;
    
    void bfs(int row, int col, vector<vector<int>>&matrix) {
    
        
        while(!q.empty()) {
            
            auto [x, y] = q.front(); q.pop();
           
            
            for(auto& direction : dir){
                 int m = direction.first + x, n = direction.second + y;
                
                 if(m < 0 or m >= row or n < 0 or n >= col or visited[m][n]) continue;
                
                 else{
                          visited[m][n] = true;
                          result[m][n] = result[x][y]+1;
                          q.push({m,n});
                 }
            }
        }
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int row = mat.size(), col = mat[0].size();
        result.resize(row, vector<int>(col, INT_MAX));
        visited.resize(row, vector<bool>(col, false));
        dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] == 0){
                     q.push({i,j});
                     result[i][j] = 0;
                     visited[i][j] = true;
                }
            }
        }
        
        bfs(row, col, mat);
        
        return result;
    }
};
