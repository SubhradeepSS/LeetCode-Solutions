class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s)<k:
            return False
        
        sub = set()
        
        for i in range(len(s)-k+1):
            curr = s[i:i+k]
            sub.add(curr)
        # print(sub)
        return 2**k==len(list(sub))
            