class Solution {
public:
    double solve(double x, int n){
        
          if(n==0)return 1;
        
          double s = solve(x, n/2);
        
          s= s*s;
        
          if((n&1)==0){
              return s;
          }
        
          return x*s;
    }
    
    double myPow(double x, int n) {
        
      double answer =  solve(x,n);
        
      return     n < 0 ? 1/answer : answer;
    }
};
