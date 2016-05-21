class Solution(object):
    def isValidSerialization(self, preorder):
        st = []
        s = preorder.split(',')
        slen = len(s)
        if s[0] != '#':
            st.append(s[0])

        i = 1;
        while st:
            if i == slen or i + 1 == slen:
                return False
            st.pop();
            if s[i+1] != '#':
                st.append(s[i+1])

            if s[i] != '#':
                st.append(s[i])
            i += 2

        if i < slen:
            return False

        return True
