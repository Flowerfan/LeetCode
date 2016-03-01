#include<iostream>
//* Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode *temp = head;
		while (temp->next != NULL) {
			if (temp->val == (temp->next)->val) {
				temp->next = temp->next->next;
				continue;
			}
			temp = temp->next;
		}
		return head;
	}
};