# Runtime: 60 ms, faster than 96.69% of Python3 online submissions for Add Two Numbers.
# Memory Usage: 14.2 MB, less than 89.79% of Python3 online submissions for Add Two Numbers.



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
	def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
		a = l1
		b = l2
		stop = False
		result = ListNode(0)
		curNode = result
		carry = 0

		i=0
		while (i<100 and stop==False):
			cur = a.val + b.val + carry
			carry = 0

			if (cur >= 10):
				carry = 1
				cur -= 10
			
			curNode.val = cur
			a = a.next
			b = b.next

			if (a == None and b == None):
				if (carry == 1):
					curNode.next = ListNode(1)
				stop = True
			else:
				if (a == None):
					a = ListNode(0)
				if (b == None):
					 b = ListNode(0)
				curNode.next = ListNode(0)
				curNode = curNode.next
		return result