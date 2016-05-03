class Solution(object):
    def isValid(self, s):
        st = []
        left_s = '({['
        for c in s:
            if c in left_s:
                st.append(c)
            elif st and \
                ((c == ')' and st[-1] == '(') \
                or (c == '}' and st[-1] == '{') \
                or (c == ']' and st[-1] == '[')):
                st.pop();
            else:
                return False

        return not st
