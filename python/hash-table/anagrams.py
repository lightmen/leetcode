class Solution(object):
    def groupAnagrams(self, strs):
        d = {}
        ret = []

        for s in strs:
            key = ''.join(sorted(s))

            if d.get(key, -1) == -1:
                d[key] = len(ret)
                ret.append([s])
                continue

            ret[d[key]].append(s)

        return ret
