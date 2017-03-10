class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        d = {word: i for i, word in enumerate(words)}
        res = []

        for index, word in enumerate(words):
            for i in range(len(word) + 1):
                right = word[i:][::-1]
                left = word[:i][::-1]
                if left in d and right == right[::-1] and index != d[left]:
                    res.append([index, d[left]])

                if i > 0 and right in d and left == left[::-1] and index != d[right]:
                    res.append([d[right], index])

        return res
