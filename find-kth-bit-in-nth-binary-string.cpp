class Solution {
public:
    string invert(const string&value){
        string answer;
        for(char val : value){
            if(val=='0')answer+="1";
            else answer+="0";
        }
        return answer;
    }
    
    void solve (int i, int n, string&value){
        
        if(i==n+1)return;
        
        else if(i==1){
            value+="0";
        }
        
        else{
            string temp = invert(value);
            reverse(temp.begin(), temp.end());
            value+="1";
            value+=temp;
        }
        
        solve(i+1,n,  value);
    }
    
    char findKthBit(int n, int k) {
        string answer;
        solve(1,n,answer);
        return answer[k-1];
    }
};
