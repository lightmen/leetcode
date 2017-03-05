class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        d = {}
        l = []
        for c in s:
            d[c] = d.get(c, 0) + 1

        for c in d:
            index = 0
            while index < len(l):
                if d[l[index]] < d[c]:
                    break
                index += 1
            l.insert(index, c)

        res = ""
        for c in l:
            res += c * d[c]

        return res
