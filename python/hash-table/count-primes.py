class Solution(object):
    def countPrimes(self, n):
        arr = [0] * n
        count = 0
        for i in xrange(2,n):
            if arr[i] != 0:
                continue
            count += 1
            for j in xrange(2*i,n,i):
                arr[j] = 1

        return count
