class Solution {
public:
    vector<vector<string>>answer;
    
    void solve(int row, int n, vector<string>&temp, vector<bool>&col, vector<bool>&left_diag, vector<bool>&right_diag){
        
         if(row == n){
             answer.push_back(temp);
         }
        
         for(int c = 0; c < n; c++){
                
               if(!col[c] and !right_diag[row+c] and !left_diag[row-c+n-1]){
                   
                    col[c] = right_diag[row+c] = left_diag[row-c+n-1] = true;
                    temp[row][c] = 'Q';
                    solve(row+1, n, temp, col, left_diag, right_diag);
                   
                    col[c] = right_diag[row+c] = left_diag[row-c+n-1] = false;
                    temp[row][c] = '.';
               }
         }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool>left_diag(2*n-1, false), right_diag(2*n-1, false), col(n,false);
        vector<string>temp(n, string(n,'.'));
        solve(0, n, temp, col, left_diag, right_diag);
        return answer;
    }
};
