class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        line = ["qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", \
            "zxcvbnmZXCVBNM"]
        res = []
        for word in words:
            for m in line:
                if word[0] in m:
                    l = m
                    break
            flag = 1
            for w in word:
                if w not in l:
                    flag = 0
                    break
            if flag:
               res.append(word)

        return res
