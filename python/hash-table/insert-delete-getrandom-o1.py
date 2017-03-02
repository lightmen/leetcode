class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = set()
        self.l = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.d:
            return False
        self.d.add(val)
        self.l.append(val)
        return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.d:
            return False
        self.d.remove(val)
        #del self.d[val]
        self.l = list(self.d)
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.l[random.randint(0, len(self.d) - 1)]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
