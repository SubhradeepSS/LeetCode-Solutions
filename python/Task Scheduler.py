class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        d1={}
        for i in range(26):
            d1.update({i:0})
        
        for i in tasks:
            d1[ord(i)-ord('A')]+=1
        
        d=sorted(d1.items(),key=lambda x:(x[1],x[0]))
        
        i=24
        max_val= d[25][1]-1
        idle_slots=max_val*n
        
        while i>=0:
            if d[i][1]>0:
                idle_slots-=min(d[i][1],max_val)
            i-=1
        
        if idle_slots>0:
            return len(tasks)+idle_slots
        return len(tasks)