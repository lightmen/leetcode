class Solution(object):
    def simplifyPath(self, path):
        st = []
        str_list = path.split('/')
        for str in str_list:
            if len(str) > 0:
                if str == '..':
                    if st:
                        st.pop()
                elif str != '.':
                    st.append(str)

        if st == []:
            return '/'
        ret = ''
        for str in st:
            ret += '/' + str

        return ret
