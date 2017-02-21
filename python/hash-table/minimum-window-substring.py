class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        init_hash = {}
        cur_hash = dict.fromkeys(t,0)
        for ch in t:
            init_hash[ch] = init_hash.get(ch, 0) + 1
        end = 0
        start = 0
        t_match = 0
        ret = ""
        for end in range(len(s)):
            if init_hash.get(s[end], 0) == 0:
                continue
            cur_hash[s[end]] += 1
            if cur_hash[s[end]] <= init_hash[s[end]]:
                t_match += 1
            if t_match < len(t):
                continue
            while init_hash.get(s[start], 0) == 0 or \
                cur_hash[s[start]] > init_hash[s[start]]:
                if cur_hash.get(s[start], 0) > 0:
                    cur_hash[s[start]] -= 1
                start += 1
            if len(ret) == 0 or end - start + 1 < len(ret):
                ret = s[start:end+1]
            t_match -= 1
            cur_hash[s[start]] -= 1
            start += 1

        return ret
