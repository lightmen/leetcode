class MinStack(object):

    def __init__(self):
        self.st = []
        self.min_st = []


    def push(self, x):
        self.st.append(x)
        if len(self.min_st) == 0 or x <= self.min_st[-1]:
            self.min_st.append(x)


    def pop(self):
        if self.st[-1] <= self.min_st[-1]:
            self.min_st.pop()
        return self.st.pop()


    def top(self):
        return self.st[-1]


    def getMin(self):
        return self.min_st[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
