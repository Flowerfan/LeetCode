#include<iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//my solution
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *start_node = new ListNode(0);
		ListNode *n1 = l1, *n2 = l2;
		ListNode *sp = start_node;
		while (n1 != NULL) {
			if (n2 == NULL) {
				sp->next = n1;
				break;
			}
			if (n1->val <= n2->val) {
				sp->next = new ListNode(n1->val);
				n1 = n1->next;
			}
			else {
				sp->next = new ListNode(n2->val);
				n2 = n2->next;
			}
			sp = sp->next;
		}
		if (n2 != NULL)
			sp->next = n2;
		return start_node->next;
	}
};

//other quick solution
//
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//	if (l1 == NULL) return l2;
//	if (l2 == NULL) return l1;
//	if (l1->val <= l2->val) {
//		l1->next = mergeTwoLists(l1->next, l2);
//		return l1;
//	}
//	else {
//		l2->next = mergeTwoLists(l1, l2->next);
//		return l2;
//	}
//}