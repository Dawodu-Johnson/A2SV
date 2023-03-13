class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        
        if n==0:
            return False
        elif n==1:
            return True
        elif n%4!=0:
            return False
        return self.isPowerOfFour(n//4)
    
# class Solution {
# public:
#     bool isPowerOfFour(int n) {
#         if(n==0)return 0;
#         double check= log(n)/log(4);
#         if(check== ceil(check))return true;
#         return false;
#     }
# };
        
