class Solution {
public:

 int answer(vector<int>&contain,int target,int sum,int siz){
     
      if(siz==-1){
        return (sum==target ? 1:0);
      }

     return (answer(contain, target, sum+ contain[siz], siz-1)+ answer(contain,target, sum-contain[siz],siz-1));
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;

        return answer(nums,target,0, nums.size()-1);

    }
};
