class Solution(object):
    def __init__(self):
        self.count = 0

    def isHappy(self, n):
        if n == 1:
            return True
        if self.count == 100:
            return False

        d = 0
        tmp = 0
        while n > 0:
            d = n % 10
            n /= 10
            tmp += (d * d)

        self.count += 1
        return self.isHappy(tmp)
