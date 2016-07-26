# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        queue = collections.deque()
        data = ''
        queue.append(root)
        while queue:
            node = queue.popleft()
            if node is None:
                data += 'null,'
            else:
                data += str(node.val) + ','
                queue.append(node.left)
                queue.append(node.right)


        return '[' + data[0:-1] + ']'

    def deserialize(self, data):
        if data == '[]':
            return None


        list_data = data[1:-1].split(',')
        nums = [0] * len(list_data)
        arr = []
        for i in range(0,len(list_data)):
            if i > 0:
                nums[i] = nums[i-1]
            if  list_data[i] == 'null':
                arr.append(None)
                nums[i] += 1
            else:
                arr.append(TreeNode(int(list_data[i])))

        for i in range(0,len(arr)):
            if arr[i] is None:
                continue
            if 2*(i-nums[i]) + 1 < len(arr):
                arr[i].left = arr[2*(i-nums[i]) + 1]
            if 2*(i-nums[i]) + 2 < len(arr):
                arr[i].right = arr[2*(i-nums[i]) + 2]

        return arr[0]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
