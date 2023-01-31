class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        
        vector<int>prefix(size+1),answer;
        prefix[0]=0;
        
        for(int i=1; i< size+1; i++){
             prefix[i]= prefix[i-1]^ arr[i-1];
        }
        
        for(const auto & query : queries){
               
                answer.push_back(prefix[query[1]+1] ^ prefix[query[0]]);
        }
        
        return answer;
    }
};
