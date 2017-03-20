class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        indexa = len(a) - 1
        indexb = len(b) - 1
        res = ''
        carry = 0
        while indexa >= 0 or indexb >= 0:
            x = int(a[indexa]) if indexa >= 0 else 0
            y = int(b[indexb]) if indexb >= 0 else 0
            value = x + y + carry
            carry = value // 2
            value = value % 2
            res = str(value) + res
            indexa, indexb = indexa - 1, indexb - 1

        if carry == 1:
            res = '1' + res

        return res
