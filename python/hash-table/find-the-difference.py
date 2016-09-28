class Solution(object):
    def findTheDifference(self, s, t):
        h = {};
        for key in s:
            if h.get(key) is None:
                h[key] = 1
            else:
                h[key] += 1

        for key in t:
            if h.get(key,0) == 0:
                return key
            h[key] -= 1
