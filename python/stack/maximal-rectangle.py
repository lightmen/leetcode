class Solution(object):
    def maxArea(self, heights):
        area = 0
        st = []

        for i in range(len(heights)):
            while st and heights[i] <= heights[st[-1]]:
                h = heights[st[-1]]
                st.pop()
                w = i if not st else (i - st[-1] - 1)

                if h * w > area:
                    area = h * w

            st.append(i)

        return area

    def maximalRectangle(self, matrix):
        if not matrix:
            return 0

        heights = [0] * (len(matrix[0])+1)
        max_area = 0;

        for row in matrix:
            for j in range(len(row)):
                if row[j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0;

            area = self.maxArea(heights)
            if area > max_area:
                max_area = area


        return max_area
