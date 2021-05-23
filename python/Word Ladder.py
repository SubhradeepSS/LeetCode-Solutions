class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or not beginWord or not endWord or not wordList:
            return 0
        
        combo_dict = collections.defaultdict(list)
        L = len(beginWord)
        
        for word in wordList:
            for i in range(L):
                combo_dict[word[:i]+'*'+word[i+1:]].append(word)
        
        queue = [(beginWord, 1)]
        visited = [beginWord]
        
        while queue:
            curr,level = queue.pop(0)
            
            for i in range(L):
                util = curr[:i]+'*'+curr[i+1:]
                
                for word in combo_dict[util]:
                    if word == endWord:
                        return level+1
                    
                    if word not in visited:
                        visited.append(word)
                        queue.append((word,level+1))
                        
                combo_dict[util] = []
        
        return 0