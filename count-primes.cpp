class Solution {
public:
    
    
    int sieve(vector<bool>&store){
        
      
        int size=store.size();
        store[0]=store[1]=false;
        store[2]=true;
        int answer=0;
        for(long long i=2; i<size; i++){
            
            if(store[i]){
                ++answer;
                for(long long j=i*i; j<size; j+=i){
                    store[j]=false;
                }
            }
        }
        return answer;
    }
    
    
    int countPrimes(int n) {
        
        if(n==0)return 0;
        int answer=0;
        
        if(n>1){
         vector<bool>store(n,true);
         answer=sieve(store);
            
        function<int(void)> sieve = [&] (){

            int size=store.size();
            store[0]=store[1]=false;
            store[2]=true;
            int answer=0;

            for(long long i=2; i<size; i++){

                if(store[i]){
                    ++answer;
                    for(long long j=i*i; j<size; j+=i){
                        store[j]=false;
                    }
                }
            }
            return answer;
     };
     sieve();
    }
        
        
        
        return answer;
    }
};
