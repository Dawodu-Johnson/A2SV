class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        
        for(int i = 0; i <=31; i++){
            int temp = 0, ones = 0;
            
            for(int &y : nums){
                int x = y;
                
                if( (x >> i) &1 ){
                    ones++;
                }
                temp = temp ^ ( (x >> i) &1);
                
            }
            
            if( (temp == 0 or temp == 1) and (ones-1)%3==0){
                // means there is a 1 in ours
                //cout << i << endl;
                answer = answer | (1 << i);
            }
        }
        
        return answer;
    }
};
