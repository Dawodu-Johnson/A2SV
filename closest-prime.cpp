class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        //just find all prime numbers between left and right 
        // look for the one with the minimum difference.
        
        vector<int>answer = {-1,-1};
        
        vector<int>isPrime(right+1,true);
        isPrime[0]=isPrime[1] = false;
        
        for(int i = 2; i <= right; i++){
            
             if(isPrime[i]){
                 
                for(long long j = 1ll*i*i; j <=right; j+=i){
                    
                       isPrime[j] = false;
                }
                 
             }
            
        }
        
        vector<int>primes;
        
        for(int i = left; i <= right; i++){
               
               if(isPrime[i]){
                       primes.push_back(i);
               }
        }
        
        if(primes.size() <2)return answer;
        
        int diff = INT_MAX;
        
        for(int i = 1; i < primes.size(); i++){
              diff = min(diff, primes[i]-primes[i-1]);
        }
        
        for(int i = 1; i < primes.size(); i++){
               if(primes[i]-primes[i-1]== diff){
                     answer = {primes[i-1],primes[i]};
                     break;
               }
        }
        
        return answer;
        
    }
};
