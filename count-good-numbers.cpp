class Solution {
public:

   
        
    long long binary_exponentiation(long long value, long long power, long long mod = 1e9+7){
        
        if(power == 0){
             return 1;
        }
        
        long long half_power = (binary_exponentiation(value, power/2, mod))%mod;
        half_power = (half_power* half_power)%mod;
        
        if(power%2==0){
            return half_power;
        }
        return (value*half_power)%mod;
    }
    
    int countGoodNumbers(long long n) {
        /*(x*y)%mod
        ((x%mod)* (y%mod))%mod
        (power((ways_even), neven)  * pow((ways_odd),nodd))%mod;*/
        
        long long mod = 1e9+7;
        long long neven = n/2, nodd = n/2;
        if(n&1){
             neven = (n/2)+1;
        }
        
        long long answer =  (binary_exponentiation(5ll, neven) *  binary_exponentiation(4ll, nodd))%mod;
        
        return (int)answer;
    }
};
