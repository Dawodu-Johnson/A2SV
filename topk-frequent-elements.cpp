class Solution {
public:
  
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>store;
        
        for(int x: nums){
            store[x]++;
        }
        
        vector<pair<int,int>>answer;
        
        for(const auto&x: store){
            answer.push_back({x.second, x.first});
        }
      
        sort(answer.begin(), answer.end(), [](const pair<int,int>&s, const pair<int,int>&a){
                if(s.first > a.first )return true;
               return false;
        });
      
        
        vector<int>ok;
        
        for(int i=0; i<k; i++){
            ok.push_back(answer[i].second);
        }
      
        return ok;
    }
};
