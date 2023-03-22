class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
            
        
        answer = []
        size_p = len(p)
        size_s = len(s)
        
        freq_p = [0]*26
        freq_s = [0]*26
        
        def check():
            
            for i in range(26):
                if freq_p[i]!=freq_s[i]:
                    return False
            
            return True
        
        if size_s < size_p:
            return []
        
        
        for i in range(size_p):
            
            freq_p[ord(p[i])-97]+=1
            freq_s[ord(s[i])-97]+=1
        
        
        for i in range(size_s-size_p+1):
            print(i)
            if check():
                answer.append(i)
            
            freq_s[ord(s[i])-97]-=1
            if i+size_p < size_s:
                freq_s[ord(s[i+size_p])-97]+=1
        
        return answer
            
