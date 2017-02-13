class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        h = [0] * 26
        for i in range(len(s)):
            h[ord(s[i]) - ord('a')] = h[ord(s[i]) - ord('a')] + 1
            h[ord(t[i]) - ord('a')] = h[ord(t[i]) - ord('a')] - 1

        for val in h:
            if val != 0:
                return False

        return True
