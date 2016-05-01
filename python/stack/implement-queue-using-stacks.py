class Queue(object):
    def __init__(self):
        self.st1 = []
        self.st2 = []

    def push(self, x):
        self.st1.append(x)

    def pop(self):
        if len(self.st2) == 0:
            while len(self.st1) != 0:
                self.st2.append(self.st1.pop())

        return self.st2.pop()

    def peek(self):
        if len(self.st2) == 0:
            while len(self.st1) != 0:
                self.st2.append(self.st1.pop())

        return self.st2[-1]

    def empty(self):
        return len(self.st1) == 0 and len(self.st2) == 0
