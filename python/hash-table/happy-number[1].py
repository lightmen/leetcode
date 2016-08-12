class Solution(object):
    def isHappy(self, n):
        s = set()

        while True:
            t = 0
            s.add(n)
            while n > 0:
                t += (n % 10) * (n % 10)
                n /= 10

            if t == 1:
                return True
            if t in s:
                return False

            n = t
