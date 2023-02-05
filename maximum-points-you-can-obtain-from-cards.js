/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(cardPoints, k) {
    if(k==0)return 0;
    
    let answer=Number.POSITIVE_INFINITY, size= cardPoints.length,subarray=size-k,
    sum=0,total=0;
    
    for (val of cardPoints){
        total+=val;
    }
    
    
    for(let i=0; i< subarray; i++){
        sum+= cardPoints[i];
    }
    
    answer=Math.min(answer,sum);
    
    for(let low=0, high=subarray; high < size;){
         sum-=cardPoints[low++];
         sum+=cardPoints[high++];
         answer=Math.min(answer,sum);
    }
    
    return total-answer;
    
    
    
    // find the min subarray of size length -k.
    
};
