class Solution(object):
    def evalRPN(self, tokens):
        ops = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.div}
        st = []
        opstr = '+-*/'
        for t in tokens:
            if t in  opstr:
                right = st.pop()
                left = st.pop()
                if(t == '/'):
                    st.append(int(ops[t](left * 1.0,right)))
                else:
                    st.append(ops[t](left,right))
            else:
                st.append(int(t))

        return st[0];
