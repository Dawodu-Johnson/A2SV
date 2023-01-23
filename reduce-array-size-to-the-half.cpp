class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>store;
        
        for(const int&x: arr)store[x]++;
        vector<int>keep;
        
        for(const auto&x: store){
             keep.push_back(x.second);
            
        }
        
        
        sort(keep.begin(), keep.end(), greater<int>());
        
        int count=0,track=0;
        for(int i=0; i< keep.size(); i++){
            if(count >= arr.size()/2){
                break;
            }
            else {
                 count+=keep[i];
                track++;
            }
        }
        
        return track;
        
    }
};
