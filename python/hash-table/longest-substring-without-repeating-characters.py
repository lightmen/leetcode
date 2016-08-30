class Solution(object):
    def lengthOfLongestSubstring(self, s):
        index = {}
        last_index = -1
        ret = 0
        for i in xrange(len(s)):
            index[s[i]] = -1

        for i in xrange(len(s)):
            last_index = index[s[i]] + 1 if last_index <= index[s[i]] else last_index
            index[s[i]] = i
            ret = (i - last_index + 1) if (i - last_index + 1) > ret else ret

        return ret
