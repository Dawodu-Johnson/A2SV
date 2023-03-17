function valid(nums:number, arr:number[], th:number):boolean {
    
       let sum:number=0;
    
       for(let i=0; i< arr.length; i++){
             sum+=Math.ceil(arr[i]/nums);
       }
    
    return sum <= th;
}


function smallestDivisor(nums: number[], threshold: number): number {
       let size:number= nums.length,left=1, right=Math.max(...nums);
       console.log(right);
       let answer:number = 0;
    
       while(left <= right){
               
            let mid:number = Math.floor(left +(right-left)/2);
            
            if(valid(mid,nums,threshold)){
                  
                  answer=mid;
                  
                   right = mid-1;
            }
           
           
            else {
                    
                   left = mid+1;
            }
            
       }
    
    return answer;
};
