
function sortit(num1:number, num2:number) : number{
          if(num1 < num2)return -1;
          else if(num1==num2)return 0;
          else return 1;
}
    

function check(weights: number[], mid:number, days:number):boolean{
     let size:number= weights.length, sum=0, count=0;
    
       for(let index:number=0; index < size; index++){
            
           if(mid < weights[index])return false;
           else if(sum+ weights[index]==mid){
                count++;
                sum=0;
           }
            else if(sum+ weights[index]<mid){
                 sum+=weights[index];
                if(index==size-1 && sum <=mid){
                    count++;
                    break;
                }
            }
            else {
                 count++;
                 sum=weights[index];
                if(index==size-1 && sum <=mid){
                    count++;
                    break;
                }
            }
           
           
       }
    console.log(count,"   ", mid);
    return count <= days;
}

function shipWithinDays(weights: number[], days: number): number {

      let right : number=0, size= weights.length,left=0,answer=Infinity;
    
     // weights.sort(sortit);
      for(let index:number=0; index < size; index++){
             right+= weights[index];
       }
      
      while(left <= right){
             
             let mid: number= Math.floor(left + (right-left)/2.0);
             //console.log(mid);
             if(check(weights,mid,days)){
                   right= mid-1;
                   answer=mid;
             }
          
             else {
                  left = mid +1;
             }
      }
    
    return answer;
    
};

