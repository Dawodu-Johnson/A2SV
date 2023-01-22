class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        if(changed.size()%2!=0)return {};
        
        sort(changed.begin(), changed.end());
        
        map<int, int>data;
        
        for(const int & val : changed){
             data[val]++;
        }
        
        vector<int>answer;
        
        for(int i =0; i < changed.size(); i++){
            
              int doub = changed[i]*2;
            
              if(data[changed[i]] >=1 && data[doub] >=1){
                        
                        if(changed[i]==0){
                            
                            if(data[0] <2) continue;
                            data[0]-=2;
                            answer.push_back(changed[i]);
                            continue;
                            
                        }
                        else{
                        data[changed[i]]--;
                        answer.push_back(changed[i]);
                        data[doub]--;
                            
                        }
                    
                  
              }
            
              
        }
        vector<int>empty;
        
        return answer.size()==(changed.size()/2)? answer : empty;
    }
};
