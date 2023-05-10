class Solution {
public:
    int hammingDistance(int x, int y) {
        int counter=0;
        
        while(x!=0 || y!=0){
            
            if((x&1) != (y&1)){
                counter++;
            }
            
            x=x>>1;
            y=y>>1;
        }
        
        
        return counter;
    }
};
