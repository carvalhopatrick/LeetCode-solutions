#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNew(int val) {
	struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
	if(!new){
		printf("erro");
		exit(1);
	}
	new->val = val;
	new->next = NULL;
	return new;
}

void addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int stop = 0;
	int i = 0;
	struct ListNode *a = l1;
	struct ListNode *b = l2;
	struct ListNode result;
	struct ListNode *curNode = &result;
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
	// return &result;

	struct ListNode* c;
	c = &result;
	while(c != NULL) {
		printf("%d", c->val);
		printf(", ");
		c = c->next;
	}
	return;
}

int main() {
	struct ListNode l1;
	l1.val = 9;
	struct ListNode l11;
	l11.val = 9;
	struct ListNode l111;
	l111.val = 9;
	l111.next = NULL;
	l11.next = &l111;
	l1.next = &l11;

	struct ListNode l2;
	l2.val = 9;
	struct ListNode l22;
	l22.val = 9;
	struct ListNode l222;
	l222.val = 9;
	l222.next = NULL;
	l22.next = &l222;
	l2.next = &l22;

	// struct ListNode* c;
	// c = &l1;
	// while(c != NULL) {
	// 	printf("%d", c->val);
	// 	printf(", ");
	// 	c = c->next;
	// }
	addTwoNumbers(&l1, &l2);

	return 0;
}