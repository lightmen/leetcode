class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        ls, lp = len(s), len(p)
        ret = []
        cp = collections.Counter(p)
        cs = collections.Counter()

        for i in range(ls):
            cs[s[i]] += 1

            if i >= lp:
                cs[s[i - lp]] -= 1
                if cs[s[i - lp]] == 0:
                    del cs[s[i - lp]]
            if cs == cp:
                ret.append(i - lp + 1)

        return ret
