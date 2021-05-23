class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = {}
        
        def f(i,j):
            if (i,j) not in dp:
                if j==len(p):
                    dp[(i,j)] = i==len(s)
                else:
                    curr = i<len(s) and p[j] in (s[i],'.')
                    
                    if j+1<len(p) and p[j+1]=='*':
                        dp[(i,j)] = f(i,j+2) or curr and f(i+1,j)
                    else:
                        dp[(i,j)] = curr and f(i+1,j+1)
            
            return dp[(i,j)]
        
        return f(0,0)