class Solution(object):
    def trap(self, height):
        if not height:
            return 0

        max_index = 0
        max_height = 0

        for i in range(len(height)):
            if height[i] > max_height:
                max_index = i
                max_height = height[i]

        max_height = 0
        i = 0
        ret = 0
        while i < max_index:
            if max_height > height[i]:
                ret += (max_height - height[i])
            else:
                max_height = height[i]
            i += 1

        max_height = 0
        i = len(height) - 1
        while i > max_index:
            if max_height > height[i]:
                ret += (max_height - height[i])
            else:
                max_height = height[i]
            i -= 1

        return ret
