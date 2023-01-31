class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        int size=chalk.size();
        
        for(const int&val : chalk)sum+=(1ll*val);
        
        int answer=0;
        if(k ==sum)return 0;
        
        else if(k > sum){
              k-=((k/sum)*sum); 
            
              for(int i=0; i< size ; i++){
                  if((k-chalk[i])>=0){
                      k-=chalk[i];
                  }
                  else return i;
              }
        }
        
        else {
             for(int i=0; i< size ; i++){
                  if((k-chalk[i])>=0){
                      k-=chalk[i];
                  }
                  else{
                       answer=i;
                       break;
                  }
              }
        }
        
        return answer;
    }
};
