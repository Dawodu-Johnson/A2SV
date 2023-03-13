class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char>data;
        vector<int>last_of_index(26,0);
        vector<int>visited(26,0);  // 0 means not visited, 1 means visited.
        
        for(int i = 0; i < s.size(); i++){
             last_of_index[s[i]-'a'] = i;
        }
        
        for(int i = 0; i < s.size(); i++){
            
            //while it is not visited, and the stack is not empty and the last element is greater than the element about to 
            // be inserted and it exists in the future
            
            if(visited[s[i]-'a']==0){
                while(!data.empty() && data.top() > s[i] && last_of_index[data.top()-'a'] >i){
                  visited[data.top()-'a']=0;
                  data.pop();
                 }
                visited[s[i]-'a']=1;
                data.push(s[i]);
            }
        }
        
        string answer;
        
        while(!data.empty()){
             answer+=data.top();
             data.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
