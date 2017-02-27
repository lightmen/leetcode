class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        ls = str.split()
        d1 = {}
        d2 = {}
        if(len(ls) != len(pattern)):
            return False
        for c1, c2 in zip(pattern, ls):
            if c1 not in d1:
                d1[c1] = c2
            if c2 not in d2:
                d2[c2] = c1
            if d1[c1] != c2 or d2[c2] != c1:
                return False

        return True
