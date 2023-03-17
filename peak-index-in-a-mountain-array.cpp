class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
         int left = 0, right = arr.size()-1, size = arr.size();
        
         while(left <= right){
               
                 int mid = left + (right-left)/2;
             
                 if(mid-1 >=0 && mid+1 < size && 
                     arr[mid] > arr[mid-1] && arr[mid] >arr[mid+1])return mid;
             
                 else if(mid+1 < size && arr[mid] < arr[mid+1]) left = mid+1;
             
                 else right = mid-1;
               
         }
        
        return 0;
    }
};
