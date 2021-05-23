class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        di={}
        
        for i in magazine:
            if i in di:
                di[i]+=1
            else:
                di[i]=1
        
        for i in ransomNote:
            if i not in di:
                return False
            di[i]-=1
            
            if di[i]==0:
                del di[i]
        return True