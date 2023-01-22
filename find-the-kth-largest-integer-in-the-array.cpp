struct sortit{
    bool operator () (const string &s, const string&s1){
        
        if(s.size() < s1.size())return true;
        
        else if(s.size() > s1.size())return false;
        
        else{
            // they are equal;
           return s < s1;
        }
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        stringstream ss;
        
        priority_queue<string, vector<string>,sortit>store;
        
        
        for(const string & val: nums){
            store.push(val);
        }
        
        for(int i=1; i<k; i++){
            store.pop();
        }
        
        string answer=store.top();
        
        return answer;
    }
};
