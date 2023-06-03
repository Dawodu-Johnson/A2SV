class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int>contains_word;
        vector<bool>visited(wordList.size(), false);
        
        int counter = 0, answer = 0;
        
        for(auto& val : wordList){
            contains_word[val] = counter++;
        }
        
        
        queue<string>bfs;
        
        bfs.push(beginWord);
        
        while(!bfs.empty()){
            
            int sz = bfs.size();
          
            for(int i = 0; i < sz; i++){
                
                string temp = bfs.front();
                bfs.pop();
                if(temp == endWord){return answer;}
                for(int i = 0; i < temp.size(); i++){
                    
                    for(char x = 'a'; x <='z'; x++){
                         if(temp[i]!=x){
                              char t = temp[i];
                              temp[i] = x;
                              if(contains_word.find(temp)!=contains_word.end() and !visited[contains_word[temp]]){
                                  if(temp == endWord){return answer+2;}
                                  bfs.push(temp);
                                  visited[contains_word[temp]] = true;
                                  
                              }
                              temp[i] = t;
                         }
                    }
                }
                
            }
              answer++;
        }
        
        return 0;
    }
};
