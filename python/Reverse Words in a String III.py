class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words=s.split(' ')
        res=[]
        for word in words:
            r="".join(reversed(word))
            res.append(r)
        re=""
        for i in res:
            re=re+str(i)+" "
        
        return re.rstrip()
        