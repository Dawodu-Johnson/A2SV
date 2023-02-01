class Solution {
public:
    int check(vector<int>&num2, int value){
        
        int size = num2.size();
        int start =-1;
        for(int i=0; i< size; i++){
              
              if(num2[i]==value){
                   start = i;
                   break;
              }
        }
        
        for(int i= start+1; i < size; i++){
            
             if(num2[i] > value){
                 return num2[i];
             }
        }
        return -1;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        
        vector<int>answer;
        int size = nums1.size();
        for(int i=0; i< size; i++){
             answer.push_back(check(nums2,nums1[i]));
        }
        return answer;
    }
};
