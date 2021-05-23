class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp={}
        for i in nums:
            if i in mp:
                mp[i]+=1
            else:
                mp.update({i:1})
        for i in mp:
            if mp[i]>len(nums)//2:
                return i
        return -1