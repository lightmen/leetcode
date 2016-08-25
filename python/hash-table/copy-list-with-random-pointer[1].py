# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        d = {}
        root = RandomListNode(0)

        d[None] = None
        saved_head = head
        prev = root
        while head:
            new_node = RandomListNode(head.label)
            prev.next = new_node
            prev = prev.next
            d[head] = new_node
            head = head.next

        head = saved_head
        while head:
            d[head].random = d[head.random]
            head = head.next

        return root.next
