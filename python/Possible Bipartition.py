from collections import defaultdict
class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        graph=defaultdict(list)
        
        for i,j in dislikes:
            graph[i].append(j)
            graph[j].append(i)
        
        color = {}
        
        def dfs(node,c=0):
            if node in color:
                return color[node]==c
            color[node]=c
            
            return all(dfs(adj,c^1) for adj in graph[node])
        
        return all(dfs(node) for node in range(1,N+1) if node not in color)