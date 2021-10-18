/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNew(int val) {
	struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
	if(!new) {
		printf("error\n");
		exit(1);
	}
	new->val = val;
	new->next = NULL;
	return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int stop = 0;
	int i = 0;
	struct ListNode *a = l1;
	struct ListNode *b = l2;
	struct ListNode *result = createNew(0);
	struct ListNode *curNode = result;
	int carry = 0;
	
    for (i=0; i<100 && stop==0; i++) {
		int cur = a->val + b->val + carry;
		carry = 0;

		if (cur >= 10) {
			carry = 1;
			cur -= 10;
		}

		curNode->val = cur;
		a = a->next;
		b = b->next;

		if (a == NULL && b == NULL) {
			if (carry == 1) curNode->next = createNew(1);
			stop = 1;
		} else {
			if (a == NULL) a = createNew(0);
			if (b == NULL) b = createNew(0);
			curNode->next = createNew(0);
			curNode = curNode->next;
		}
	}
	return result;
}