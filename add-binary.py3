class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        
        def convert(c):
            counter = 0
            answer = 0
            
            for i in reversed(range(len(c))):
                answer+=(int(c[i])* (1 << counter))
                counter+=1
            
            return answer
      
        store = convert(a) + convert(b)
        
        if store == 0:
            return "0"
        
        answer = ""
        
        while store > 0:
            
            if store%2 !=0 :
                answer+='1'
            else:
                answer+='0'
                
            store//=2
            
        return answer[::-1]
    
    
                
                
