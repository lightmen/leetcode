# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        self.st = []

        i = len(nestedList) - 1
        while i >= 0:
            self.st.append(nestedList[i])
            i -= 1


    def next(self):
        nested = self.st[-1]
        self.st.pop()
        return nested.getInteger()


    def hasNext(self):
        while self.st:
            nested = self.st[-1]
            if nested.isInteger():
                return True
            self.st.pop()
            nestedList = nested.getList()
            i = len(nestedList) - 1
            while i >= 0:
                self.st.append(nestedList[i])
                i -= 1

        return False


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
