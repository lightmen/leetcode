class Solution(object):
    def numTrees(self, n):
        num = [0] * (n+1)
        num[0] = num[1] = 1
        for i in range(2,n+1):
            for j in range(i):
                num[i] += (num[j] * num[i-j-1])

        return num[n]
