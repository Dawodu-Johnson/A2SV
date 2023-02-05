class Solution {
public:
    
    bool check(vector<int>&va1, vector<int>&va2){
        
        
        for(int i=0; i<26; ++i){
            
            if(va1[i]!= va2[i])return false;
            
        }
        
        return true;
        
    }
    
    
    vector<int> findAnagrams(string s, string p) {
        
        
        vector<int>answer;
        if(s.size() < p.size())return answer;
        vector<int>char1(26,0);
        vector<int>char2(26,0);
        
        int size1= p.size();
        int size2= s.size();
        
        for(int i=0; i<size1; ++i){
            char1[p[i]-'a']++;
            char2[s[i]-'a']++;
        }
        
        for(int i=0; i< size2-size1+1; ++i){
            
            if(check(char1, char2)){
                answer.push_back(i);
            }
            
            if(i+size1 < size2){char2[s[i]-'a']--;
            char2[s[i+size1]-'a']++;
                               }
            
        }
        
        
        
        
        return answer;
    }
};
