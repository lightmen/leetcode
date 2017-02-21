class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        line = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        res = []
        for word in words:
            for m in line:
                if word[0].lower() in m:
                    l = m
                    break
            flag = 1
            for w in word:
                if w.lower() not in l:
                    flag = 0
                    break
            if flag:
               res.append(word)

        return res
