class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        d = set()
        res = set()
        for i in range(len(s)-9):
            if s[i:i + 10] in d:
                res.add(s[i:i + 10])
            else:
                d.add(s[i:i + 10])

        return list(res)
