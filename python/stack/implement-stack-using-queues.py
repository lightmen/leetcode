class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []


    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        if self.q1:
            self.q1.append(x)
            while self.q2:
                self.q1.append(self.q2[0])
                self.q2.pop()
        else:
            self.q2.append(x)
            while self.q1:
                self.q2.append(self.q1[0])
                self.q1.pop()

    def pop(self):
        """
        :rtype: nothing
        """
        if self.q1:
            self.q1.pop()
        else:
            self.q2.pop()


    def top(self):
        """
        :rtype: int
        """
        if self.q1:
            return self.q1[-1]
        else:
            return self.q2[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return not self.q1 and not self.q2
