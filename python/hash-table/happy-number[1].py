class Solution(object):
    def isHappy(self, n):
        s = set()

        while True:
            s.add(n)
            n = sum([int(x) * int(x) for x in list(str(n))])
            if n == 1 or n in s:
                break

        return n == 1
