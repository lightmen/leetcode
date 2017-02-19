class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        init_hash = [0] * 256
        cur_hash = [0] * 256
        for ch in t:
            init_hash[ord(ch)] += 1

        end = 0
        start = 0
        t_match = 0
        ret = ""
        for end in range(len(s)):
            if init_hash[ord(s[end])] == 0:
                continue

            cur_hash[ord(s[end])] += 1

            if cur_hash[ord(s[end])] <= init_hash[ord(s[end])]:
                t_match += 1

            if t_match < len(t):
                continue

            while init_hash[ord(s[start])] == 0 or \
                cur_hash[ord(s[start])] > init_hash[ord(s[start])]:
                if cur_hash[ord(s[start])] > 0:
                    cur_hash[ord(s[start])] -= 1
                start += 1

            if len(ret) == 0 or end - start + 1 < len(ret):
                ret = s[start:end+1]

            t_match -= 1
            cur_hash[ord(s[start])] -= 1
            start += 1

        return ret
