class Solution {
public:
    
    int answer(unordered_map<int, int>cell_value, int n){
        vector<bool>visited(n*n+1,false);
        queue<int>q;
        q.push(1);
        int counter = 0, range, value, next;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0;  i < sz; i++){
                value = q.front(); q.pop();
                if(value == n*n) return counter;
                range = min(value+6, n*n);
                visited[value] = true;
                for(int node =value+1; node <= range; node++){
                        next = cell_value.count(node) ? cell_value[node] :node; 
                        if(!visited[next]){
                            visited[next] = true;
                            q.push(next);
                        }
                }
            }
           counter++;
        }
        
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size(), counter = 0, value = 0;
        
        unordered_map<int, int>cell_value;
        
        for(int i = row; i >= 1; i--) {
            for(int j = 1; j <=col; j++) {
                value = (row-i)*row + j;
               
                if(counter&1){
                    if(board[i-1][col-j]!=-1) cell_value[value] = board[i-1][col-j];
                }
                else{
                    if(board[i-1][j-1]!=-1)cell_value[value] = board[i-1][j-1];
                }
            }
            counter++;
        }
        
        return answer(cell_value, col);
    }
};
