class Solution(object):
    def isIsomorphic(self, s, t):
        ms = {}
        mt = {}

        for i in range(len(s)):
            if ms.get(s[i],-1) != mt.get(t[i],-1):
                return False

            ms[s[i]] = i
            mt[t[i]] = i

        return True
