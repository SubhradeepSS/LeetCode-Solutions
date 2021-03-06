class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.ds = []
        

    def add(self, key: int) -> None:
        if key not in self.ds:
            self.ds.append(key)

    def remove(self, key: int) -> None:
        if key in self.ds:
            self.ds.remove(key)

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return key in self.ds


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)