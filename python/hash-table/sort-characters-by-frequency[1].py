class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ''.join(c * t for c, t in collections.Counter(s).most_common())
