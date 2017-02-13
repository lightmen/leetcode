class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False

        d = dict()

        for i in range(len(s)):
            d[s[i]] = d[s[i]] + 1 if d.has_key(s[i]) else 1
            d[t[i]] = d[t[i]] - 1 if d.has_key(t[i]) else -1

        for i in range(len(s)):
            if d.get(s[i],0) != 0:
                return False

        return True
