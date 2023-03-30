class Solution {
public:
    bool check(vector<int>&c, int mid){
        
         int f = lower_bound(c.begin(), c.end(), mid)-c.begin();
     
         int l = c.size()-f;
         if(l >=mid)return true;
        return false;
    }
    
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());
        
        int left = 1, right = citations.size(), answer = 0;
        
        
        
        while(left <= right){
            
             int mid = left + (right-left)/2;

             if(check(citations, mid)){
               
                  answer = mid;
                  left = mid+1;
             }
            
             else{
                 right = mid - 1;
             }
            
        }
        
        return answer;
        
    }
};
