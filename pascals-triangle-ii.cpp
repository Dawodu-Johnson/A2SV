class Solution {
public:
 
 
    
    void solve(int i, int row, vector<int>&answer){
        
        if(i-1== row){
            return;
        }
        
        vector<int>temp;
        if(i == 0){
             answer.push_back(1);
        }
        else if(i ==1){
             answer.push_back(1);
        }
        
        else{
            
            temp.push_back(1);
            for(int k = 1; k < answer.size(); k++){
                 temp.push_back(answer[k] + answer[k-1]);
            }
            temp.push_back(1);
            answer = temp;
        }
        solve(i+1, row, answer);
    }
    
    vector<int> getRow(int rowIndex) {
        
         vector<int>answer;
        
         solve(0, rowIndex, answer);
         return answer;
    }
};
