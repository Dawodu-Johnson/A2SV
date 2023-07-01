class Solution {
public:
    
    vector<pair<int, int>>dir;
    
    int bfs(int i, int j, vector<vector<char>>&maze, vector<int>&entrance) {
        
        vector<vector<bool>>vis(maze.size(), vector<bool>(maze[0].size(),false));
        
        queue<pair<int, int>>q;
        
        q.push({i,j});
        int counter = 0;
        
        while(!q.empty()) {
            
            int sz = q.size();
            
            for(int p = 0; p < sz; p++) {
                
                auto [x , y] = q.front(); q.pop();
                
                if( (x==0 or y==0 or x == maze.size()-1 or y ==maze[0].size()-1) and (x!=i or y!=j) ) {
                    return counter;
                }
                
                vis[x][y] = true;

                for(auto& d:  dir){
                    int m = d.first+x, n = d.second + y;
                    
                    if(m < 0 or m >=maze.size() or n < 0 or 
                       n>=maze[0].size() or vis[m][n] or maze[m][n] == '+')continue;
                    
                    vis[m][n] = true;
                    q.push({m,n});
                }
            }
          
            counter++;
        }
        
        return INT_MAX;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // do a bfs at the boarders
        int row = maze.size(), col = maze[0].size(), answer = INT_MAX;
        dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
      
        /*for(int i = 0; i < row; i++){
            answer = min(answer,min(bfs(i, 0, maze, entrance), bfs(i, col-1, maze, entrance)));
        }
        for(int i = 0; i < col; i++){
            answer = min(answer, min(bfs(0, i, maze, entrance), bfs(row-1, i, maze, entrance)));
        }*/
        answer = bfs(entrance[0], entrance[1], maze, entrance);
        
        return answer==INT_MAX ? -1 : answer;
    }
};
