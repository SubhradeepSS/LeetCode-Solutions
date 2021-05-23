class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        di=Counter(t)
        curr={}
        req=len(di)
        cl=0
        ans=float('inf'),None,None
        l,r=0,0
        
        while r<len(s):
            add=s[r]
            curr[add]=curr.get(add,0)+1
            if add in di and di[add]==curr[add]:
                cl+=1
            while l<=r and cl==req:
                sub=s[l]
                if r-l+1<ans[0]:
                    ans=r-l+1,l,r
                curr[sub]-=1
                
                if sub in di and curr[sub]<di[sub]:
                    cl-=1
                l+=1
            r+=1
        return "" if ans[0]==float('inf') else s[ans[1]:ans[2]+1]