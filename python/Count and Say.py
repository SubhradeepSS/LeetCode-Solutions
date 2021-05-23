class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1:
            return '1'
        if n==2:
            return '11'
        s='11'
        for _ in range(n-2):
            c=1
            x=''
            for i in range(len(s)-1):
                if s[i]==s[i+1]:
                    c+=1
                else:
                    x+=str(c)+s[i]
                    c=1
            x+=str(c)+s[-1]
            s=x
        return s