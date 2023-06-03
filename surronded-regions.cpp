class Solution {
public:
    vector<pair<int, int>>dir;
    
    void dfs(int row, int col, vector<vector<bool>>&visited, vector<vector<char>>&board){
        
        if(row < 0 or col < 0 or row >= board.size() or col >= board[0].size()  or visited[row][col] or  board[row][col]=='X'){
            return;
        }
        
        visited[row][col] = true;
        
        for(auto& d: dir){
            
              int x  = d.first + row, y = d.second + col;
            
              dfs(x,y, visited, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        // do a dfs at every border
        int row = board.size(), col = board[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col,false));
        
        dir = { {0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for(int i = 0; i < col; i++){
            
            if(!visited[0][i] and board[0][i]=='O'){
                  dfs(0, i, visited, board);
            }
            
            if(!visited[row-1][i] and board[row-1][i]=='O'){
                  dfs(row-1, i, visited, board);
            }
        }
        
        for(int i = 0; i< row; i++){
            
            if(!visited[i][0] and board[i][0]=='O'){
                  dfs(i, 0, visited, board);
            }
            
            if(!visited[i][col-1] and board[i][col-1]=='O'){
                  dfs(i, col-1, visited, board);
            }
            
        }
        
        for(int i = 0; i < row; i++){
            
             for(int j = 0; j < col; j++){
                 
                    if(!visited[i][j] and board[i][j] == 'O'){
                          board[i][j] = 'X';
                    }
             }
        }
        
        
    }
};
