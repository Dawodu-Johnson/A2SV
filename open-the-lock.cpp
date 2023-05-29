class Solution {
public:
    
    
    int openLock(vector<string>& deadends, string target) {
       string ini = "0000", temp, pos;
        
       unordered_set<string>invalid(deadends.begin(), deadends.end());// visited;
        
       if(invalid.find(ini)!= invalid.end())return -1;
        
       deque<string>data;
        
        data.push_front(ini);
        
        int answer = 0;
        
        while(!data.empty()){
            
            int sz = data.size();
            
            for(int i = 0; i < sz; i++){
                
                temp = data.front();
                data.pop_front();
                
                if(temp == target)return answer;
                
                for(int j = 0; j < 4; j++){
                    
                       int d = temp[j] - '0', res = d;
                       d = (d+1)%10;
                       temp[j] = d + '0';
                      
                       if(invalid.find(temp)== invalid.end() and visited.find(temp)==visited.end()){
                            
                             visited.insert(temp);
                             data.push_back(temp);
                       }
                      
                       temp[j] = res + '0';  //restore
                    
                       d = temp[j] - '0';
                       d = (d-1);
                       if( (d-1) < 0){
                              d = 9;
                       }
                       temp[j] = d + '0';
                       
                       if(invalid.find(temp)== invalid.end() and visited.find(temp)==visited.end()){

                             visited.insert(temp);
                             data.push_back(temp);
                       }
                      
                       temp[j] = res + '0';
                }
                
            }
            
            answer++;
        }
        
        return -1;
    }
};
