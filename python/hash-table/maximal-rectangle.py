class Solution(object):
    def maximalRectangle(self, matrix):
        if len(matrix) == 0:
            return 0

        max_area = 0
        st = [0] * (len(matrix[0]) + 1)
        height = [0] * (len(matrix[0]) + 1)
        for i in range(len(matrix)):
            top = -1
            for j in range(len(matrix[i]) + 1):
                if j < len(matrix[i]):
                    height[j] = ((height[j] + 1) if (matrix[i][j] == '1') else 0)

                while top > -1 and height[j] < height[st[top]]:
                    h = height[st[top]]
                    top -= 1
                    w = j if (top == -1) else (j - st[top] - 1)
                    if h * w > max_area:
                        max_area = h * w
                top += 1
                st[top] = j

        return max_area
