class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int maxi = 1;
        
        if(arr[0]!=1){
            arr[0] = 1;
        }
        
        for(int i = 1; i < arr.size(); i++){
            if((arr[i]- arr[i-1]) >=2){
                arr[i] = arr[i-1]+1;
            }
            maxi = max(maxi, arr[i]);
        }
        
        return maxi;
    }
};
