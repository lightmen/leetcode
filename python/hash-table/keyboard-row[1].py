class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        s1 = set("qwertyuiop")
        s2 = set("asdfghjkl")
        s3 = set("zxcvbnm")

        res = []
        for word in words:
            sw = set(word.lower())
            if sw.issubset(s1) or sw.issubset(s2) or sw.issubset(s3):
                res.append(word)

        return res
