class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      
        unordered_map<string,int >store;
        
        for(const string & s: words){
            store[s]++;
        }
        
        vector<pair<string,int>>ss;
        
        for(const auto&x: store){
            ss.push_back({x.first, x.second});
        }
        
        sort(ss.begin(), ss.end(), [](const pair<string, int>&a, const pair<string, int>&b){
            if(a.second > b.second)return true;
            else if(a.second < b.second)return false;
            return a.first < b.first;
        });
        
        vector<string>answer;
        
        for(int i=0; i<k; i++){
          answer.push_back(ss[i].first);
        }
        return answer;
    }
};
