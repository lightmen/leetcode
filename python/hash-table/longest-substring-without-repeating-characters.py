class Solution(object):
    def lengthOfLongestSubstring(self, s):
        index = {}
        last_index = 0
        ret = 0
        for i in xrange(len(s)):
            if index.get(s[i],-1) >= last_index:
                last_index = index[s[i]] + 1
            index[s[i]] = i
            ret = max((i - last_index + 1),ret)

        return ret
