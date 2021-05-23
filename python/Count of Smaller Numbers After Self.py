class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        copy = nums[:]
        copy.sort()
        
        ans = []
        
        for n in nums:
            i = bisect.bisect_left(copy,n)
            copy.pop(i)
            ans.append(i)
        
        return ans