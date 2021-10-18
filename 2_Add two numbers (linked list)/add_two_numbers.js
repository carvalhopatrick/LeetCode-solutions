/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
 var addTwoNumbers = function(l1, l2) {
	let stop = false;
	let i = 0;
	let a = l1;
	let b = l2;
	let result = new ListNode;
	curNode = result;
	let carry = 0;
    for (i=0; i<100 && stop === false; i++) {
		let cur = a.val + b.val + carry;
		carry = 0;

		if (cur >= 10) {
			carry = 1;
			cur -= 10;
		}

		curNode.val = cur;

		a = a.next;
		b = b.next;

		if (a === null && b === null) {
			if (carry === 1) curNode.next = new ListNode(1);
			stop = true;
		} else {
			if (a === null) a = new ListNode(0)
			if (b === null) b = new ListNode(0)
			curNode.next = new ListNode(0);
			curNode = curNode.next;
		}
	}
	return result;
};