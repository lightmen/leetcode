class Solution(object):
    def dist(self, x1, y1, x2, y2):
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)

    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        ret = 0
        for i in range(len(points)):
            d = {}
            for j in range(len(points)):
                if i == j:
                    continue
                key = self.dist(points[i][0], points[i][1], \
                    points[j][0], points[j][1])
                ret += (2 * d.get(key,0))
                d[key] = d.get(key, 0) + 1

        return ret
