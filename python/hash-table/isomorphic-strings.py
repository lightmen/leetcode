class Solution(object):
    def isIsomorphic(self, s, t):
        slen = len(s)
        flag = {}
        visited = {}

        for i in range(slen):
            if flag.get(s[i],-1) == -1:
                if visited.get(t[i],-1) != -1:
                    return False

                flag[s[i]] = t[i]
                visited[t[i]] = 1
            elif flag.get(s[i]) != t[i]:
                return False

        return True
