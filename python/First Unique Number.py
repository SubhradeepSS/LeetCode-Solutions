class FirstUnique(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.l=[]
        self.d=OrderedDict()
        for i in nums:
            self.l.append(i)
            if i in self.d:
                self.d[i]+=1
            else:
                self.d.update({i:1})

    def showFirstUnique(self):
        """
        :rtype: int
        """
        for i in self.d:
            if self.d[i]==1:
                return i
        return -1

    def add(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.l.append(value)
        if value in self.d:
            self.d[value]+=1
        else:
            self.d.update({value:1})


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)