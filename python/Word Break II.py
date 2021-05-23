class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        
        @lru_cache(None)
        def f(i):
            if i==0:
                return [[]]
            
            ans = []
            
            for w in wordDict:
                if s[i-len(w):i] == w:
                    ans.extend([x+[w] for x in f(i-len(w))])
                
            return ans
        
        return [' '.join(w) for w in f(len(s))]