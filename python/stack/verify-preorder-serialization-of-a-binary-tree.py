class Solution(object):
    def isValidSerialization(self, preorder):
        count = 0
        s = preorder.split(',')
        slen = len(s)
        if s[0] != '#':
            count += 1

        i = 1;
        while count:
            if i == slen or i + 1 == slen:
                return False
            count -= 1
            if s[i] != '#':
                count += 1
            if s[i+1] != '#':
                count += 1
            i += 2

        if i < slen:
            return False

        return True
