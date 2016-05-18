class Solution(object):
    def removeDuplicateLetters(self, s):
        count = collections.Counter(s)
        st = []

        for ch in s:
            count[ch] -= 1
            if ch in st:
                continue
            while st and ch < st[-1] and count[st[-1]] > 0:
                st.pop()
            st.append(ch)

        return ''.join(st)
