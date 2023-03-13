class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        
        if n <=0:
            return False
        
        def solve(val: int):
            
            if val==1:
                return True
            
            elif val==0:
                return False
            
            elif val%3!=0:
                return False
            
            return solve(val//3)
        
        return solve(n)
      
# class Solution {
# public:
#     bool isPowerOfThree(int n) {
        
#       if(n==0)return 0;
#         if(n < 0)return false;

#         double store= log10(n)/log10(3);
#         double check= store- (int)store;
#         if(check >0)return false;
#         else return true;
        
#     }
# };
    
        
