class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        
        total, five, ten = 0, 0, 0
        
        for i in range(len(bills)):
            
            if bills[i] == 5:
                five+=1
            elif bills[i] == 10 :
                ten+=1
                if five > 0:
                    five-=1
                else:
                    return False
            else:
                if ten > 0 and five > 0:
                    ten-=1
                    five-=1
                elif five >=3:
                    five-=3
                else:
                    return False
            
        return True
    
                
