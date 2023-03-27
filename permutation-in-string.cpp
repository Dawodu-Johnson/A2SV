class Solution {
public:
    bool check(vector<int>&va1, vector<int>&va2){
        
        int size= va1.size();
        
        
        for(int i=0; i<26; ++i){
             if(va1[i]!= va2[i])return false; 
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() <s1.size())return false;
        
        vector<int>Char1(26,0);
        vector<int>Char2(26,0);
        
        int size1= s1.size();
        int size2= s2.size();
        
        for(int i=0; i<size1; ++i){
            
            Char1[s1[i]-'a']++;
            
            Char2[s2[i]-'a']++; 
            
        }
        
        for(int i=0; i<size2-size1+1; ++i){
            
            if(check(Char1, Char2))return true;
            
            if(i+size1 < size2){Char2[s2[i]-'a']--;
               Char2[s2[i+size1]-'a']++;}
        }
        
        return false;
        
        
    }
};
