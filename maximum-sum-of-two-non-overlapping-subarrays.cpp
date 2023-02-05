class Solution {
public:
    
    vector<int>prefix_sum;
    vector<vector<int>>dp1;
    vector<int>dp2;
    
    int compute(int l, int r){
        //cout << "sr" << l << " " << r << endl;
       return (l-1)>=0 ? prefix_sum[r]-prefix_sum[l-1]: prefix_sum[r];
    }
    
    int get(int index, int s, vector<int>&nums, int size){
        int pick =-3000, dont = pick, answer =-3000;
        
        if(index >= size)return 0;
        else if(dp1[index][s]!=-1)return dp1[index][s];
        for(int start = index; start < size; start++){
               
               if(start+ s-1 < size){
                   pick = compute(start, start+s-1);
               }
            
               dont = get(index+1, s, nums,size);
               answer = max(answer,max(pick,dont));
        }
        
        return dp1[index][s]= answer;
    }
    
    
    
    int solve(int start1, int f, int s, vector<int>&nums, int size){
        int pick = -3000, dont =pick, answer = pick;
        if(start1 >= size)return 0;
       else if(dp2[start1]!=-1){
            return dp2[start1];
        }
        for(int  index = start1; index < size; index++){
            
              int pick = -3000;
              // we have two options actually, we can start at a particular index or not.
              if(index+f-1 < size && index+f+s-1 <size){
                  pick = compute(index,index+f-1)+ get(index+f,s,nums,size);
                  // now let us go and solve for the other one
              }
              if(index+s-1 < size && index+s+f-1 < size){
                   pick = max(pick, compute(index, index+s-1)+ get(index+s, f,nums, size));
              }
            
             dont  = solve(start1+1, f, s, nums, size);
             answer = max(answer,max(dont,pick));
        }
        
        return dp2[start1]= answer;
        
    }
    
    
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        prefix_sum.resize(nums.size());
        prefix_sum[0]= nums[0];
        
        dp1.resize(nums.size(), vector<int>(firstLen+secondLen+1,-1));
        dp2.resize(nums.size(),-1);
        
        for(int i = 1; i < nums.size(); i++){
               prefix_sum[i] = prefix_sum[i-1]+nums[i];
        }
       // cout << get(0,3, nums, nums.size()) << endl;
        return solve(0, firstLen, secondLen, nums, nums.size());
    }
};
