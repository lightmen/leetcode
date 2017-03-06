class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = collections.defaultdict(set)
        self.l = []

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        bool_ret = val not in self.l
        self.d[val].add(len(self.l))
        self.l.append(val)
        return bool_ret

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.l:
            return False
        last_val = self.l.pop()
        self.d[last_val].remove(len(self.l))
        if val != last_val:
            index = self.d[val].pop()
            self.l[index] = last_val
            self.d[last_val].add(index)

        if not self.d[val]:
            del self.d[val]
        return True

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return self.l[random.randint(0, len(self.l) - 1)]

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
