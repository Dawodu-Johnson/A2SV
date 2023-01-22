class Solution {
public:
    
    struct sortit{
        bool operator() (const int & num1, const int& num2){
            
              string one = to_string(num1);
              string two = to_string(num2);
            
              string temp1 = one+two;
              string temp2 = two+one;
            
             if(temp1 > temp2)return true;
            else return false;
        }
    };
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), sortit());
        
        string answer;
        
        for(const int&val: nums){
             
             string temp;
             temp = to_string(val);
            
             answer+=temp;
        }
        return (answer[0]=='0') ? "0":answer;
    }
};
