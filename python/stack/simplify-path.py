class Solution(object):
    def simplifyPath(self, path):
        st = []
        i = 0
        j = 0
        plen = len(path)
        while j < plen:
            while j < plen and path[j] == '/':
                j += 1
            if j == plen:
                break

            i = j
            while j < plen and path[j] != '/':
                j += 1

            str = path[i:j]
            if str == '.':
                continue

            if str == '..':
                if st:
                    st.pop()
            else:
                st.append(str)

        if st == []:
            return '/'

        ret = ''
        for str in st:
            ret += '/' + str

        return ret
