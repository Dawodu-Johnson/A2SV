/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
       let answer=[], size= nums.length;
    
       for(let i=0; i < size; i++){
              
               let counter=0;
           
               for(let back=0; back < i; back++){
                    
                     if(nums[back] < nums[i])++counter;
               }
           
               for(let front=i+1; front < size; front++){
                    if(nums[front] < nums[i])++counter;
               }
           
               answer.push(counter);
       }
    
       return answer;
};
