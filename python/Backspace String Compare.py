class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        while S.find('#')!=-1:
            i=S.find('#')
            if i==0:
                S=S[i+1:]
            else:
                S=S[:i-1]+S[i+1:]
        while T.find('#')!=-1:
            i=T.find('#')
            if i==0:
                T=T[i+1:]
            else:
                T=T[:i-1]+T[i+1:]
        return (S==T)