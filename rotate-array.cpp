class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(k==nums.size())return;
        int siz=nums.size();

        k=k%siz;
        vector<int>answer(k);
            int back=siz-1;
          while(k>0){
              answer[k-1]=nums[back];
              --back;
              --k;
          }
        
            int stop=back;
            for(int i=0; i<=back;++i){
                answer.emplace_back(nums[i]);
                ++stop;
            }
        
            nums=answer;
        
        
                
    }
};
