class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>answer;
        vector<vector<int>>data_base(26);
        int size = s.size();
        
        for(int i = 0 ; i < size; i++){
            data_base[s[i]-'a'].push_back(i);
        }
        
        int low = 0, high =0;
        vector<int>temp = data_base[s[high]-'a'];
        int val = temp[temp.size()-1];
        
        for(low =0, high =0; high < size; high++){
             
               // while the beginning index is present in that one .
            
                 if(data_base[s[high]-'a'][0] > val){
                     
                         answer.push_back(high-low);
                         low = high;
                         val = data_base[s[high]-'a'][data_base[s[high]-'a'].size()-1];
                 }
                 else{
                        val = max(val, data_base[s[high]-'a'][data_base[s[high]-'a'].size()-1]);
                 }
            
        }
        
        if(low!=high){
            answer.push_back(high-low);
        }
        
        return answer;
    }
};
