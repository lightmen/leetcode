class Solution(object):
    def largestRectangleArea(self, heights):
        max_area = 0
        st = []
        heights.append(0)
        hlen = len(heights)
        i = 0;

        while i < hlen:
            while st and heights[i] <= heights[st[-1]]:
                h = heights[st[-1]]
                st.pop()
                w = i
                if st:
                    w = i - st[-1] - 1
                if h * w > max_area:
                    max_area = h * w

            st.append(i)
            i += 1

        return max_area;
