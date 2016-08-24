# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        root = RandomListNode(0)
        root.next = head
        while head:
            new_node = RandomListNode(head.label)
            new_node.next = head.next
            head.next = new_node
            head = head.next.next

        head = root.next
        while head:
            new_node = head.next
            if head.random:
                new_node.random = head.random.next

            head = head.next.next


        prev = root
        head = root.next
        while head:
            new_node = head.next
            head.next = head.next.next
            prev.next = new_node
            prev = new_node
            head = head.next

        return root.next
