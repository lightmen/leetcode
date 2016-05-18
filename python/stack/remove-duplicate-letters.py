class Solution(object):
    def removeDuplicateLetters(self, s):
        h = {}
        st = []

        for ch in s:
            if ch in h.keys():
                h[ch] += 1
            else:
                h[ch] = 1

        for ch in s:
            h[ch] -= 1
            if ch in st:
                continue

            while st and ch < st[-1] and h[st[-1]] > 0:
                st.pop()

            st.append(ch)

        return ''.join(st)
