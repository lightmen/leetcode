class Solution(object):
    def evalRPN(self, tokens):
        ops = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.div}
        st = []
        for t in tokens:
            if t in  ('+','-','*','/'):
                right = st.pop()
                left = st.pop()
                if(t == '/'):
                    left *= 1.0
                st.append(int(ops[t](left,right)))
            else:
                st.append(int(t))

        return st[0];
