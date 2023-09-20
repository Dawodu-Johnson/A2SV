class Solution {
public:
    // uhmm -_-
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
      
        long long answer = 0;
        
        function<bool(long long, int)> solve = [&](long long mid, int index) {
            long long bud= 0;
            for(int i = 0; i < composition[index].size(); i++) {
                bud += 1ll*max(0ll,(1ll*mid*composition[index][i])-stock[i])*cost[i];
                if(bud > budget)return false;
            }
            return true;
        };
        
      for(int i = 0; i < k; i++) {
          long long left = 1, right = 1e9;
          while(left <= right) {
              long long mid = left + (right-left)/2;
              if(solve(mid, i)) {
                  answer = max(answer, mid);
                  left = mid+1;
              }
              else {
                  right = mid-1;
              }
          }
          
      }
          
      return (int)answer;
    }
};
