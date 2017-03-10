class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        d = {word: i for i, word in enumerate(words)}
        res = collections.defaultdict(set)

        for index, word in enumerate(words):
            for i in range(len(word)):
                r_suf = word[i:][::-1]
                w = r_suf + word
                if r_suf in d and w == w[::-1] and index != d[r_suf]:
                    res[d[r_suf]].add(index)

                r_pre = word[:i][::-1]
                w = word + r_pre
                if r_pre in d and w == w[::-1] and index != d[r_pre]:
                    res[index].add(d[r_pre])

                if "" in d and word == word[::-1] and index != d[""]:
                    res[d[""]].add(index)
                    res[index].add(d[""])

        return [[key, value] for key, values in res.items() for value in values]
