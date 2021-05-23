class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        firstCost = [i for i,j in costs]
        diff = [j-i for i,j in costs]
        return sum(firstCost)+sum(sorted(diff)[:len(diff)//2])